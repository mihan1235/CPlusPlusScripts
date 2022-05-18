/*
 * set.cpp
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
#include <set>
using namespace std;

struct Bid {
	int num_of_bird;
	int price;
	int num_shares;
	std::string user_id;
	Bid(int num_of_bird,int price,int num_shares,const char* user_id){
		this->num_of_bird=num_of_bird;
		this->price=price;
		this->num_shares=num_shares;
		this->user_id.assign(user_id);
	}
	bool operator < (const Bid & x) const {
		if (price<=x.price){
			return true;
		}
		return false;
	}
	friend std::ostream& operator<<(std::ostream& stream,const Bid& bid){
		stream<<"      Number of bid: "<<"["<<bid.num_of_bird;
		stream<<"]\n";
		stream<<"      Price for one share: "<<"[";
		stream<<bid.price<<"]\n";
		stream<<"      Number of shares: "<<"["<<bid.num_shares;
		stream<<"]\n";
		stream<<"      Id of user who sent bid: "<<"[";
		stream<<bid.user_id<<"]\n";
		return stream;
	}
};

int main(int argc, char **argv)
{
	std::set<Bid> set;
	cout<<"size of set: "<<set.size()<<endl;
	set.insert(Bid(23,324,23,"mihan"));
	set.insert(Bid(1,3245,234,"fach"));
	set.insert(Bid(244,3124,2343,"dffs"));
	set.insert(Bid(132,124,43,"sfsf"));
	set.insert(Bid(24,324,343,"hghhh"));
	cout<<"size of set: "<<set.size()<<endl;
	std::set<Bid>::const_iterator point;
	point=set.begin();
	int i=0;
	while (point!=set.end()){
		std::cout<<"["<<i<<"]\n";
		std::cout<<*point;
		//point->operator<(*point++);
		point++;
		i++;
	}
	return 0;
}

