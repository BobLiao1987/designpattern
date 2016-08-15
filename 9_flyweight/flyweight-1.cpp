#include <iostream>
#include <string>
#include <vector>

using namespace std;


enum PieceColor {BLACK,WHITE};
struct PiecePose
{
    int x;
    int y;
    PiecePose(int a, int b):x(a),y(b){}
};

class Piece
{
protected:
    PieceColor m_color;
    PiecePose m_pos;
public:
    Piece(PieceColor color, PiecePose pos):m_color(color), m_pos(pos){}
    ~Piece(){}
    virtual void Draw(){}
};
class BlackPiece:public Piece
{
public:
    BlackPiece(PieceColor color, PiecePose pos):Piece(color,pos){}
    ~BlackPiece(){}
    virtual void Draw(){cout<<" draw black piece"<<endl;}
};
class WhitePiece:public Piece
{
public:
    WhitePiece(PieceColor color, PiecePose pos):Piece(color,pos){}
    ~WhitePiece(){}
    virtual void Draw(){cout<<" draw white piece"<<endl;}
};


class PieceBoard
{
private:
    std::vector<Piece*> m_vecPiece;
    string m_blackName;
    string m_whiteName;
public:
    PieceBoard(string black, string white): m_blackName(black), m_whiteName(white){}
    ~PieceBoard()
    {
        Clear();
    }
    void SetPiece(PieceColor color, PiecePose pos)
    {
        Piece* piece = nullptr;
        if(color == BLACK)
        {
            piece = new BlackPiece(color, pos);
            cout<< m_blackName<<" at postion:("<<pos.x<<","<<pos.y<<")";
            piece->Draw();
        }
        else
        {
            piece = new WhitePiece(color, pos);
            cout<< m_whiteName<<" at position:("<<pos.x<<","<<pos.y<<")";
            piece->Draw();
        }
        m_vecPiece.push_back(piece);
    }

    void Clear()
    {
        int size = m_vecPiece.size();
        for(int i=0;i<size;i++)
            delete m_vecPiece[i];
    }

};

int main(int argc, char const *argv[])
{
    PieceBoard pieceBoard("A","B");
    pieceBoard.SetPiece(BLACK,PiecePose(4,4));
    pieceBoard.SetPiece(WHITE,PiecePose(4,16));
    pieceBoard.SetPiece(BLACK,PiecePose(16,4));
    pieceBoard.SetPiece(WHITE,PiecePose(16,16));

    return 0;
}
