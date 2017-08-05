#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required
  --------------------------------*/
# define CS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !?:;,.$&<>()+*-_="

struct s_node {
  char c;
  struct s_node *prev;
  struct s_node *next;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
char *precious(int *text, int size);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/

struct s_node *ft_dlstnew (char c);
void  ft_dlstadd(struct s_node **alst, struct s_node *new, int ht);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
