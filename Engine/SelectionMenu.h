#pragma once

#include "RectI.h"
#include "SpriteCodex.h"
#include "Mouse.h"
#include "PixelFont.h"
#include "Hammer.h"


class SelectionMenu
{
public:
	enum class Gamemode
	{
		Classic,
		Mouse,
		NumberPad,
		Count1,
		Replay,
		Exit,
		Count2,
		Invalid
	};
	enum class Menutype {
		StartMenu,
		EndMenu
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
			case Gamemode::Replay:
				font.DrawString(rect.GetCenter() - Vei2{ fontsize * 19,fontsize * 3 }, "replay", gfx, fontsize, Colors::Green);
				break;
			case Gamemode::Exit:
				font.DrawString(rect.GetCenter() - Vei2{ fontsize * 23,fontsize * 3 }, "exit", gfx, fontsize, Colors::Green);
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
		menuhammer(pos,Hammer::hammerState::StillUp),
		font(font)

	{
		auto center = pos;
		for( int i = 0; i < int( Gamemode::Count1 ); i++ )
		{
			entries[i] = { Gamemode( i ),center };
			center.y += verticalSpacing;
		}
		Vei2 leftcorner = { 0,Graphics::ScreenHeight };
		auto botleft = leftcorner - (leftcorner - pos) / 2;
		for (int i = int(Gamemode::Count1); i<int(Gamemode::Count2); i++) {
			entries[i] = { Gamemode(i+1),botleft };
			botleft.x = Graphics::ScreenWidth - botleft.x;
		}
	}
	// returns Size::Something when an entry is clicked, otherwise returns Size::Invalid
	Gamemode ProcessMouse( const Mouse::Event& e ,Menutype mtype,float dt)
	{
		if (mtype == Menutype::StartMenu) {
			menuhammer.MouseUpdate(dt, e,!e.IsValid());
			switch (e.GetType())
			{
			case Mouse::Event::Type::Move:
				for (int i = 0; i<int(Gamemode::Count1); i++)
				{
					if (entries[i].IsHit(e.GetPos()))
					{
						// need to test here to prevent sfx from firing
						// on every mouse move event
						if (!entries[i].IsHighlighted())
						{
							ResetHighlights();
							entries[i].SetHighlight();
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
				for (int i = 0; i<int(Gamemode::Count1); i++)
				{
					if (entries[i].IsHit(e.GetPos()))
					{
						return entries[i].GetMode();
					}
				}
				break;
			}
		}
		else{
			menuhammer.MouseUpdate(dt, e, !e.IsValid());
			switch (e.GetType())
			{
			case Mouse::Event::Type::Move:
				for (int i = int(Gamemode::Count1); i<int(Gamemode::Count2)-1; i++)
				{
					if (entries[i].IsHit(e.GetPos()))
					{
						// need to test here to prevent sfx from firing
						// on every mouse move event
						if (!entries[i].IsHighlighted())
						{
							ResetHighlights();
							entries[i].SetHighlight();
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
				for (int i = int(Gamemode::Count1); i<int(Gamemode::Count2) - 1; i++)
				{
					if (entries[i].IsHit(e.GetPos()))
					{
						return entries[i].GetMode();
					}
				}
				break;
			}
		}
		return Gamemode::Invalid;
	}
	void Draw( Graphics& gfx ,Menutype type) const
	{
		if (type==Menutype::StartMenu) {
			for (int i = 0;i<int(Gamemode::Count1);i++)
			{
				entries[i].Draw(gfx, font);
			}
			menuhammer.DrawHammer(gfx);
		}
		else {
			for (int i = int(Gamemode::Count1); i<int(Gamemode::Count2)-1; i++)
			{
				entries[i].Draw(gfx, font);
			}
			menuhammer.DrawHammer(gfx);
		}
	}
	void SilenceHammer();
private:
	void ResetHighlights()
	{
		for( auto& n : entries )
		{
			n.ResetHighlight();
		}
	}
private:
	Hammer menuhammer;
	const PixelFont& font;
	static constexpr int verticalSpacing = 80;
	Sound hover = { L"menu_boop.wav" };
	Entry entries[ int(Gamemode::Count2)-1];

};