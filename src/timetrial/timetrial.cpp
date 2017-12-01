#include "timetrial/timetrial.hpp"
#include "object/player.hpp"
#include "supertux/sector.hpp"


TimeTrial::TimeTrial() :
	timerAsCoins(true),
	badguys(false),
	coinsToTime(false),
	blockCoinsToTime(true),
	dying(false),
	coin_timer(1),
	dying_timer(),
	player(0)
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
