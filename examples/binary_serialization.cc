#include<iostream>
#include<iomanip>
#include"../include/fast_io.h"
#include<string>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<unordered_set>

int main()
{
	{
	std::vector<std::array<std::array<std::size_t,3>,2>> arr{std::array<std::array<std::size_t,3>,2>{std::array<std::size_t,3>{12142141,2,3},std::array<std::size_t,3>{4,5,6}}};
	fast_io::obuf out("binary_serialization.txt");
	write(out,arr);
	std::array<std::string,1> ar{"abcdef\n dsjfgoisdjgoisdjgdiso"};
	write(out,ar);
	std::vector<std::deque<std::list<std::array<std::unordered_set<std::size_t>,3>>>> lol;
	write(out,lol);
	}//auto release the file handle by destructor
	{
	std::deque<std::array<std::array<std::size_t,3>,2>> arr;
	fast_io::ibuf in("binary_serialization.txt");
	read(in,arr);
	for(auto const& e : arr)
		for(auto const& e1:e)
			for(auto const & e2 : e1)
				std::cout<<e2<<'\n';
	std::string str;
	read(in,str);
	std::cout<<str<<'\n';
	}
}