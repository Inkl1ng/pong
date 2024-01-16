#include "Bot.hpp"

#include "../Paddle.hpp"

Pong::Bot::Bot(sf::RenderWindow& window, Pong::Paddle& paddle, Pong::Ball& ball)
    : r_window {window}
    , r_paddle {paddle}
    , r_ball   {ball}
{

}

void Pong::Bot::make_move()
{
    if ((r_paddle.get_side() == Pong::Paddle_side::left && r_ball.get_vel().x > 0.0f)
        || (r_paddle.get_side() == Pong::Paddle_side::right && r_ball.get_vel().x < 0.0f))
    {
        return;
    }
    else
    {
        // const float paddle_top = r_paddle.get_pos().y - r_paddle.get_dimensions().y / 2.0f;
        // const float paddle_bot = r_paddle.get_pos().y + r_paddle.get_dimensions().y / 2.0f;
        const float paddle_top = r_paddle.get_pos().y - 10.0f;
        const float paddle_bot = r_paddle.get_pos().y + 10.0f;

        if (r_ball.get_pos().y > paddle_top && r_ball.get_pos().y < paddle_bot)
        {
            return;
        }
        else if (r_ball.get_pos().y < paddle_bot)
        {
            r_paddle.move_up();
        }
        else
        {
            r_paddle.move_down();
        }
    }
}
