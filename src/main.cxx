#include "bit_io.hxx"
#include "common.hxx"
using namespace ipd;
using namespace std;

int main(int argc, const char* argv[])
{
    // YOUR CODE HERE
    bofstream out("example.txt");
    assert_good(out, argv);

    out << false;

    out.write(true);
    out.write(true);
    out.write(false);
    out.write(false);
    out.write(false);
    out.write(false);
    out.write(true);

    out.write(false);
    out.write(true);
    out.write(true);
    out.write(false);
    out.write(false);
    out.write(false);
    out.write(true);
    out.write(false);

    return 0;
}
