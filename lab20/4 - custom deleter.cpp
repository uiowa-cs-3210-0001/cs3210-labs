#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct file_deleter
{
    std::string filename;
    
    void operator()(FILE* ptr) const
    {
        cout << "closing " << filename << endl;
        fclose( ptr );
    }
};

using file_handle = unique_ptr<FILE,file_deleter>;


int main()
{
    file_handle file1( fopen( "hello.txt", "w" ), file_deleter{ "hello.txt" } );
    file_handle file2( file1 );
}
