#include "db.h"
#include "db_constants.h"

namespace CR
{
    DB::DB()
    {
    }

    DB::~DB()
    {
    }

    std::tuple<bool, std::string> DB::init(const std::string &db_path)
    {
        bool ret = true;
        std::string error;

        return std::make_tuple(ret, error);
    }

    void DB::reset_db()
    {
    }

}
