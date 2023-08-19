#ifndef MARKED_H
#define MARKED_H
#include <string>
const int TAB_WIDTH = 4;
namespace markdown
{
    class Parser
    {
    public:
        Parser();
        virtual ~Parser();

    private:
        std::string toString();
    };
};
#endif // MARKED_H