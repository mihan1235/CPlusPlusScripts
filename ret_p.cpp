/*
 * ret_p.cpp
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
#include <string>

using std::cout;
using std::cin;
using std::endl;

struct Point {
	int a;
	int b;
	std::string str;
	Point(){
		a=1;
		b=a;
	}
};

Point* g(){
	return new Point;
}

void f(Point* p) {
	p=g();
	p->a=1;
	p->b=2;
	p->str.assign("afafasfsffa");
	//return p;
}




int main(int argc, char **argv)
{
	Point *p;
	f(p);
	cout<<p->a<<endl;
	cout<<p->b<<endl;
	cout<<p->str<<endl;
	return 0;
}

