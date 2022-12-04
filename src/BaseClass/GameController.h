#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

//#includes

namespace BA_Engine
{

    /// <summary>
    /// Manages the state of a game
    /// </summary>
    class GameController
    {
    private:

        bool isRunning;

    public:

        /// <summary>
        /// Put all the pieces in place
        /// </summary>
        virtual void setup() = 0;

        /// <summary>
        /// Setup the game board
        /// </summary>
        virtual void start() = 0;

        /// <summary>
        /// Cycle the game
        /// </summary>
        virtual void update(const float pElapsedTime) = 0;

        /// <summary>
        /// Clear the game board
        /// </summary>
        virtual void shutdown() = 0;

        /// <summary>
        /// Confirms that the game is still running
        /// </summary>
        bool getIsRunning()
        {
            return isRunning;
        }

    };

}

#endif //GAME_CONTROLLER_H