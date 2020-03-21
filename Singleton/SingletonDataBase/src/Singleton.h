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
    virtual int getPopulation(const std::string& name) = 0;
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
    
    int getPopulation(const std::string& name) override
    {
        return capitals[name];
    }
};

class DummyDatabase: public Database
{
    std::map<std::string, int> capitals;
public:
    DummyDatabase()
    {
        capitals["alpha"] = 120;
        capitals["beta"] = 120;
        capitals["gamma"] = 120;
    }
    
    int getPopulation(const std::string& name)
    {
        return capitals[name];
    }
};

struct SingletonRecorderFinder
{
    int totalPopulation(std::vector<std::string> names)
    {
        int result = 0;
        for (auto& name: names)
            result += SingletonDatabase::get().getPopulation(name);
        return result;
    }
};

/*!
 * We can move singleton::get() out of the recordfinder
 * dependency inversion
 */
struct ConifgurableRecordFinder
{
    Database& db;

    explicit ConifgurableRecordFinder(Database& db)
        :db(db)
    {
    }

    int totalPopulation(std::vector<std::string>& names)
    {
        int result = 0;
        for (auto& name: names)
            result += db.getPopulation(name);
        return result;
    }
};