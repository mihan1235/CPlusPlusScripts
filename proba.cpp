/*
 * proba.cpp
 * 
 * Copyright 2016 mihan <mihan@hp-ab217ng>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	void *p=malloc(1*sizeof(int)+15*sizeof(char));
	int * p_int = (int*)p;
	*p_int=15;
	char* p_str=(char*)(p_int+sizeof(int));
	p_str[0]='a';
	p_str[1]='b';
	p_str[2]='c';
	p_str[3]='d';
	p_str[4]='d';
	p_str[5]='d';
	p_str[6]='d';
	p_str[7]='d';
	p_str[8]='d';
	p_str[9]='\0';
	printf("%i %s\n",*p_int,p_str);
	free(p);	
	return 0;
}

