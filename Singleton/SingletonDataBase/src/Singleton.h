#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <boost/lexical_cast.hpp>

class Database
{
public:
    virtual int get_population(const std::string& name) = 0;
};

class SingletonDatabase : public Database
{
    std::map<std::string, int> capitals;

    SingletonDatabase()
    {
        std::string city, num;
        
        std::cout << "Initializing database" << std::endl;
        
        std::ifstream ifs("capitals.txt");
        while(getline(ifs, city))
        {
            getline(ifs, num);
            int pop = boost::lexical_cast<int>(num);
            capitals[city] = pop;
        }
    }
public:
    SingletonDatabase(const SingletonDatabase&) = delete;
    void operator=(const SingletonDatabase&) = delete;

    static SingletonDatabase& get()
    {
        static SingletonDatabase db;
        return db;
    }
    
    int get_population(const std::string& name) override
    {
        return capitals[name];
    }
};
