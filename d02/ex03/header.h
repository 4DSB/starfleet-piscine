#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_player {
  char  *timeStamp;
  int   score;
  char  *name;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_player **mergeSort(struct s_player **players);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_player **genRandomPlayers(int n);
struct s_player *createRandomPlayer(char *name, char *timeStamp);
void printPlayers(struct s_player **players);

/*--------------------------------
  &  your own other function
  --------------------------------*/
void mergeSort_helper(struct s_player **players, int l, int r);
void mergeSort_helper(struct s_player **players, int l, int r);

#endif
