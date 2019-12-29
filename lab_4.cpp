#include <boost/filesystem.hpp>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
using namespace boost::filesystem;



struct Broker
{
	string name;
	string account;
	int date;
	int count;
};

vector <Broker> broker;



void bypass(path s)
{
	const path p{ s };
	try
	{
		for (boost::filesystem::directory_entry& x : boost::filesystem::directory_iterator(p))
		{
			if (is_directory(x)) bypass(x.path());
			else if (x.path().stem().string().substr(x.path().stem().string().length() - 3, 3) != "old" && x.path().stem().string().substr(0, 7) == "balance")
			{
				cout << x.path().parent_path().filename() << ": " << x.path().filename() << endl;
				string name = x.path().parent_path().filename().string();
				string account = x.path().filename().string().substr(8, 8);
				int date = atoi(x.path().filename().string().substr(17, 25).c_str());
				int point = 0;
				for (auto i = 0; i < broker.size(); i++)
				{
					if (broker[i].name == name && broker[i].account == account)
					{
						if (broker[i].date < date) broker[i].date = date;
						broker[i].count++;
						point = 1;
					}
				}
				if (point == 0)
				{
					broker.push_back({ name, account, date, 1 });
				}

			}
		}
	}
	catch (const filesystem_error & ex)
	{
		cout << ex.what() << endl;
	}
}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	path p;
	if (argc < 2)
	{
		p = { "C:\\Users\\tinlock\\source\\repos\\filesystem\\ftp\\" };
	}
	else
	{
		p = { argv[1] };
	}

	bypass(p);
	cout << endl;
	for (auto i : broker)
	{
		cout << "broker: " << i.name << " account: " << i.account << " count: " << i.count << " lastdate: " << i.date << endl;
	}
	return 0;
}
