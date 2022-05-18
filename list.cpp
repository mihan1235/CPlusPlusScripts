/*
 * list.cpp
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
#include <list>

using namespace std;

int main(int argc, char **argv)
{
	list<char> lst; // создание пустого списка
	int i ;
	for(i=0; i<10; i++){
		 lst .push_back ( 'A'+i);
	}
	cout << "Размер = " << lst. size () << endl;
	list<char>::iterator p;
	cout << "Содержимое: ";
	while(!lst.empty()) {
		p = lst.begin();
		cout << *p;
		lst.pop_front();
	}
	p=lst.begin();
	
	return 0;
}

