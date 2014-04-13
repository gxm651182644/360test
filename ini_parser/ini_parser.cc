#include "ini_parser.h"
#include <string>

#include <iostream>
using namespace std;

namespace qh
{
	INIParser::INIParser()
	{
	}


	bool qh::INIParser::Parse(const char* ini_data, size_t ini_data_len, const std::string& line_seperator, const std::string& key_value_seperator)
	{
		//cout<<"sss"<<endl;
		//return true;
		int i;
		string str=ini_data;
		string s;
		if(ini_data_len<1 || line_seperator.size()<1 || key_value_seperator.size()<1)
			return false;

		for(i=0; i<ini_data_len; i++)
		{
			int pos=str.find(line_seperator,i);
			if(pos==-1)
				break;
			else if(pos<ini_data_len)
			{
				s=str.substr(i,pos-i);
				cout<<s<<endl;
				if( s.size()>0)
				{
					int pos2=s.find(key_value_seperator,0);
					if(pos2==-1){
						i=pos+line_seperator.size()-1;
						continue;
					}
					string key=s.substr(0,pos2);
					trimString(key);
					mymap.insert(map<string,string>::value_type(key,s.substr(pos2+key_value_seperator.size(),s.size()-pos2-key_value_seperator.size())));
				}

				i=pos+line_seperator.size()-1;
			}
		}
		s=str.substr(i,ini_data_len-i);
		if(s.size()>0)
		{
			int pos2=s.find(key_value_seperator,0);
			if(pos2==-1)
				return false;
			string key=s.substr(0,pos2);
			mymap.insert(map<string,string>::value_type(key,s.substr(pos2+key_value_seperator.size(),s.size()-pos2-key_value_seperator.size())));
		}

		return true;
	}


	const std::string& INIParser::Get(const std::string& key, bool* found)
	{
		if(found!=NULL)
			*found=false;
		if(!key.empty() && key.size()>0){
			string& re=mymap[key];
			if(found!=NULL)
				*found=!re.empty();
			return re;
		}
		else
			return "";
	}

	const std::string& INIParser::Get(const std::string& section, const std::string& key, bool* found)
	{
		if(section.size()>0)
			Parse(section.data(),section.size());

		return Get(key,found);

	}

	INIParser::~INIParser()
	{
	}


}
