#include <iostream>
#include <map>
#include <string>
#include <queue>

using namespace std;

class NFRedisCommand
{
public:
    NFRedisCommand( const std::string& cmd )
    {
        mxParam.push_back( cmd );
    }

    ~NFRedisCommand()
    {

    }

    template <typename T>
    NFRedisCommand& operator<<( const T& t )
    {
        std::stringstream str;
        str << t;
        mxParam.push_back(str.str());
        return *this;
    }

    std::string Serialize() const
    {
        std::stringstream xDataString;
        xDataString << '*' << mxParam.size() << NFREDIS_CRLF;
        std::vector<std::string>::const_iterator it = mxParam.begin();
        for ( ; it != mxParam.end(); ++it )
        {
            xDataString << '$' << it->size() << NFREDIS_CRLF;
            xDataString << *it << NFREDIS_CRLF;
        }

        return xDataString.str();
    }

    bool Build(std::vector<const char*>& argv, std::vector<size_t>& argvlen) const
    {
        if (mxParam.empty())
            return false;

        argv.resize(mxParam.size());
        argvlen.resize(mxParam.size());

        int j = 0;
        for (auto it = mxParam.begin(); it != mxParam.end(); ++it, j++)
        {
            argv[j] = it->c_str();
            argvlen[j] = it->length();
        }
        return true;
    }

private:
    std::vector<std::string> mxParam;
};


int main(void) {
    

    return EXIT_SUCCESS;
}
