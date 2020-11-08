#include <fstream>
#include <string>
            
using namespace std;

class IBacktracking
{
    public:

        vector<vector<int>> cards;

        vector<vector<int>> board;

        virtual ~IBacktracking() {}
        
        void Load5x5();
        void Load6x6();
        void Load7x7();
        void Load8x8();

        void LoadData(string filename);

        void LeftCards();
        
        // Abstract method for the processing 
        virtual void Process() = 0;
};