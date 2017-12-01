#ifndef HEADER_SUPERTUX_TIMETRIAL_TIMETRIAL_HPP
#define HEADER_SUPERTUX_TIMETRIAL_TIMETRIAL_HPP

#include "scripting/exposed_object.hpp"
#include "scripting/player.hpp"
#include "sprite/sprite_ptr.hpp"
#include "supertux/direction.hpp"
#include "supertux/moving_object.hpp"
#include "supertux/physic.hpp"
#include "supertux/player_status.hpp"
#include "supertux/script_interface.hpp"
#include "supertux/sequence.hpp"
#include "supertux/timer.hpp"

class Badguy;
class Player;
class Sector;

class TimeTrial
{
	TimeTrial();
	~TimeTrial();
	public:
		bool timetrialMode;
		bool timerAsCoins;
		bool badguys;
		bool coinsToTime;
		bool blockCoinsToTime;
		bool dying;
		float coin_timer;
		Timer dying_timer;
		Player* player;

		virtual void update(float elapsed_time);

		static bool getTimeTrial(); 
};

#endif