#include "bit_io.hxx"
#include "common.hxx"
using namespace ipd;
using namespace std;

void send_data(const char* argv[])
{
    bofstream out("example-out.txt");
    assert_good(out, argv);
    //The encoding of `Y` is 01011001
    out << false << true;
    out << false << true << true;
    out << false << false << true;

    //The encoding of `Z` is 01011010
    out << false << true;
    out << false << true << true;
    out << false << true << false;


    //The encoding of ` ` is 00100000
    out << false << false;
    out << true << false << false;
    out << false << false << false;

    // 73 is the ASCII encoding of `I`
    // 73 in binary is 01001001
    // we use false for 0 and true for 1
    // so the following code writes `I` to the file
    out << false;
    out << true << false << false;
    out << true << false << false;
    out << true;

    // The encoding of `P` is 01010000
    out << false << true;
    out << false << true;
    out << false << false << false << false;

    // The encoding of `D` is 01000100
    out << false << true << false << false;
    out << false << true << false << false;

    // The encoding of the newline character is 00001010
    out << false << false << false << false;
    out << true << false;
    out << true << false;

    return;
}

void fetch_data(const char* argv[]) {
    bifstream in("example-in.txt");
    assert_good(in, argv);

    for (;;) {
        bool bits[8];
        for (int x = 0; x < 8; ++x) {
            in >> bits[x];
        }
        if (!in) break;
        unsigned char c = 0;
        for (int x = 0; x < 8; ++x) {
            printf("%d", bits[x]);
            c |= bits[x] << (7-x);
        }
        printf(" %c\n", c);
    }
}

int main(int argc, const char* argv[]) {
    send_data(argv);
    fetch_data(argv);
    return 0;
}
