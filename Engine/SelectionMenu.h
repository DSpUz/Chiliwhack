#pragma once

#include "RectI.h"
#include "SpriteCodex.h"
#include "Mouse.h"
#include "Sound.h"
#include "PixelFont.h"


class SelectionMenu
{
public:
	enum class Gamemode
	{
		Classic,
		Mouse,
		NumberPad,
		Count,
		Invalid
	};
private:
	class Entry
	{
	public:
		Entry() = default;
		Entry( Gamemode s,const Vei2& pos )
			:
			s( s ),
			rect( RectI::FromCenter( pos,sizeselWidth / 2,sizeselHeight / 2 ) )
		{}
		void Draw( Graphics& gfx, const PixelFont& font) const
		{
			if( highlighted )
			{
				gfx.DrawRect( rect.GetExpanded( highlightThickness ),highlightColor );
			}			
			gfx.DrawRect( rect,Colors::Black );
			switch (s)		
			{
			case Gamemode::Classic:
				font.DrawString(rect.GetCenter() - Vei2{fontsize*24,fontsize*3}, "classic", gfx, fontsize, Colors::Green);
				break;
			case Gamemode::Mouse:
				font.DrawString(rect.GetCenter() - Vei2{ fontsize * 19,fontsize * 3 }, "mouse", gfx, fontsize, Colors::Green);
				break;
			case Gamemode::NumberPad:
				font.DrawString(rect.GetCenter() - Vei2{ fontsize * 23,fontsize * 3 }, "numpad", gfx, fontsize, Colors::Green);
				break;
			}
		}
		bool IsHit( const Vei2& pt ) const
		{
			return rect.Contains( pt );
		}
		void ResetHighlight()
		{
			highlighted = false;
		}
		void SetHighlight()
		{
			highlighted = true;
		}
		bool IsHighlighted() const
		{
			return highlighted;
		}
		Gamemode GetMode() const
		{
			return s;
		}
	private:
		static constexpr int sizeselWidth = 240;
		static constexpr int sizeselHeight = 56;
		static constexpr int fontsize = 3;
		static constexpr int highlightThickness = 2;
		static constexpr Color highlightColor = Colors::Green;
		bool highlighted = false;
		Gamemode s;
		RectI rect;
	};
public:
	SelectionMenu( const Vei2& pos,const PixelFont& font ):
		font(font)
	{
		auto center = pos;
		for( int i = 0; i < int( Gamemode::Count ); i++ )
		{
			entries[i] = { Gamemode( i ),center };
			center.y += verticalSpacing;
		}
	}
	// returns Size::Something when an entry is clicked, otherwise returns Size::Invalid
	Gamemode ProcessMouse( const Mouse::Event& e )
	{
		switch( e.GetType() )
		{
		case Mouse::Event::Type::Move:
			for( auto& n : entries )
			{
				if( n.IsHit( e.GetPos() ) )
				{
					// need to test here to prevent sfx from firing
					// on every mouse move event
					if( !n.IsHighlighted() )
					{
						ResetHighlights();
						n.SetHighlight();
						hover.Play();
					}
					// immediately exit if found a hit
					// (if we don't, highlight will be reset below)
					return Gamemode::Invalid;
				}
			}
			// if no entry was hit, reset all highlights
			ResetHighlights();
			break;
		case Mouse::Event::Type::LPress:
			for( auto& n : entries )
			{
				if( n.IsHit( e.GetPos() ) )
				{
					return n.GetMode();
				}
			}
			break;
		}
		return Gamemode::Invalid;
	}
	void Draw( Graphics& gfx ) const
	{
		for( const auto& n : entries )
		{
			n.Draw( gfx ,font);
		}
	}
private:
	void ResetHighlights()
	{
		for( auto& n : entries )
		{
			n.ResetHighlight();
		}
	}
private:
	const PixelFont& font;
	static constexpr int verticalSpacing = 80;
	Sound hover = { L"menu_boop.wav" };
	Entry entries[int( Gamemode::Count )];
};