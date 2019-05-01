#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/back/state_machine.hpp>
#include <string_view>
#include <string>
#include <iostream>

using namespace boost;
using namespace std;


struct player_def 
    : msm::front::state_machine_def<player_def>
{
    using self = player_def;

    // states
    struct stopped : msm::front::state<> {};
    struct playing : msm::front::state<> {};
    struct paused : msm::front::state<> {};

    // events
    struct play_event {};
    struct stop_event {};
    struct pause_event {};

    void do_play( play_event const& )   { cout << "play" << endl; }
    void do_stop( stop_event const& )   { cout << "stop" << endl; }
    void do_pause( pause_event const& ) { cout << "pause" << endl; }
    void do_resume( play_event const& ) { cout << "resume" << endl; }

    using transition_table = mpl::vector<
          a_row<stopped, play_event,  playing, &self::do_play>
        , a_row<playing, stop_event,  stopped, &self::do_stop>
        , a_row<playing, pause_event, paused,  &self::do_pause>
        , a_row<paused,  play_event,  playing, &self::do_resume>
        , a_row<paused,  stop_event,  stopped, &self::do_stop>
        >;

    using initial_state = stopped;
};


using player = msm::back::state_machine<player_def>;


int main()
{
    player p;
    p.start();
    p.process_event( player::play_event() );
    p.process_event( player::pause_event() );
    p.process_event( player::play_event() );
    // p.process_event( player::stop_event() );
}
