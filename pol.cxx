/*
 * pol.cxx
 * 
 * Copyright 2016 Mihan <mihan@hp-ab217ng>
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

class Foo {
    public:
        int x;
        virtual void print();
};

class Bar: public Foo {
    public:
        int y;
        virtual void print();
};

void Foo::print() {
    std::cout << "x: " << this->x << '\n';
}

void Bar::print() {
    std::cout << "x: " << this->x << " y: " << this->y << '\n';
}

void print(Foo foo) {
    foo.print();
}

void print2(Foo &foo) {
    foo.print();
}

void print3(Foo *foo) {
    foo->print();
}

int main() {
    Bar bar;
    bar.x = 5;
    bar.y = 10;

    print(bar);
    print2(bar);
    print3(&bar);
}


