#ifndef MOVE_H
#define MOVE_H

void move(char*, int*, int*, int*, int*);
void push(char*, int*, int*, int*, int*, int*, int*);

#ifdef PULL
void pull(int*, int*, int*, int*, int*, int*);
#endif

#endif
