#include "timetrial/timetrial.hpp"
#include "object/player.hpp"
#include "supertux/sector.hpp"
#include "badguy/badguy.hpp"


TimeTrial::TimeTrial() :
	timerAsCoins(true), // Allows timer to be coins
	badguys(false),	// Turns badguys off
	coinsToTime(false),	// Normal coins don't contribute to time
	blockCoinsToTime(true), // Allows coins in blocks to contribute to time
	dying(false), 
	coin_timer(1), // Turns the coin timer on
	dying_timer(), // Turns the dying timer on
	player(0) // Allows the mode to access the players
	{
		 player->get_status()->add_coins(Sector::current()->player->get_coins()*-1+30);
	}

void
TimeTrial::update(float elapsed_time)
{
	if (badguys == false) {
		coin_timer -= elapsed_time;
		if(coin_timer < 0){
			player->get_status()->add_coins(-1);
			coin_timer = 1;
		}
	}

	if((Sector::current()->player->get_coins() <= 0 && badguys == false) || (dying && dying_timer.check())) {
	    dying = true;
	    Sector::current()->stop_looping_sounds();
	    //Player::set_bonus(NO_BONUS, true);
    return;
  }
}
