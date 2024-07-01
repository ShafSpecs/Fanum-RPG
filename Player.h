#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(int start_x, int start_y, int max_moves);

    void move(char direction);

    int x, y;
    int moves_left;
};

#endif //PLAYER_H
