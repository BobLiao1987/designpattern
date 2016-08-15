#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum PieceColor {BLACK, WHITE};
struct PiecePos
{
int x;
int y;
PiecePos(int a, int b):x(a),y(b){}
};

class Piece
{
protected:
    PieceColor m_color;
public:
    Piece(PieceColor color):m_color(color){}
    ~Piece(){}
    virtual void Draw(){}
};
class BlackPiece:public Piece
{
public:
    BlackPiece(PieceColor color):Piece(color){}
    ~BlackPiece(){}
    virtual void Draw(){cout<<" draw black piece"<<endl;}
};
class WhitePiece:public Piece
{
public:
    WhitePiece(PieceColor color):Piece(color){}
    ~WhitePiece(){}
    virtual void Draw(){cout<<" draw white piece"<<endl;}
};

class PieceBoard
{
private:
    std::vector<PiecePos> m_vecPos;
    Piece *m_blackPiece;
    Piece *m_whitePiece;
    string m_blackName;
    string m_whiteName;
public:
    PieceBoard(string black, string white):m_blackName(black),m_whiteName(white)
    {
        m_blackPiece = nullptr;
        m_whitePiece = nullptr;
    }
    ~PieceBoard()
    {
        delete m_whitePiece;
        delete m_blackPiece;
    }
    void SetPiece(PieceColor color, PiecePos pos)
    {
        if(color==BLACK)
        {
            if(m_blackPiece==nullptr)
                m_blackPiece = new BlackPiece(color);
            cout<<m_blackName << " at postion:("<<pos.x<<","<<pos.y<<")";
            m_blackPiece->Draw();
        }
        else
        {
            if(m_whitePiece ==nullptr)
                m_whitePiece = new WhitePiece(color);
            cout<<m_whiteName << " at postion:("<<pos.x<<","<<pos.y<<")";
            m_whitePiece->Draw();
        }
        m_vecPos.push_back(pos);
    }
};


int main(int argc, char const *argv[])
{
    PieceBoard pieceBoard("A","B");
    pieceBoard.SetPiece(BLACK,PiecePos(4,4));
    pieceBoard.SetPiece(WHITE,PiecePos(4,16));
    pieceBoard.SetPiece(BLACK,PiecePos(16,4));
    pieceBoard.SetPiece(WHITE,PiecePos(16,16));

    return 0;
}
