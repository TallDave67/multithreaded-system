#ifndef _DB_H_
#define _DB_H_

#include "db_constants.h"
#include <string>
#include <sstream>
#include <tuple>

namespace CR
{
    class DB
    {
    public:
        DB();
        ~DB();

        std::tuple<bool, std::string> init(const std::string &db_path);

        void reset_db();

    private:
    };
}

#endif
