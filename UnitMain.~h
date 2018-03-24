//---------------------------------------------------------------------------
#ifndef UnitMainH
#define UnitMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "Polynom.hpp"
//---------------------------------------------------------------------------
class TPoltnomForm : public TForm
{
__published:	// IDE-managed Components
        TEdit *EditA;
        TEdit *EditB;
        TEdit *EditC;
        TLabel *lbSquareX;
        TLabel *lbX;
        TEdit *EditA2;
        TLabel *lbSquareX2;
        TEdit *EditB2;
        TEdit *EditC2;
        TLabel *lbX2;
        TLabel *lbPolynom;
        TLabel *lbPolynom2;
        TRichEdit *reOutPut;
        TButton *ButtonCalculate;
        TLabel *lbBoundaries;
        TEdit *EditScope2;
        TEdit *EditVal;
        TLabel *lbVal;
        TCheckBox *cbAddition;
        TCheckBox *cbSubtraction;
        TCheckBox *cbValueInPoint;
        TCheckBox *cbDarivativValue;
        TCheckBox *cbIntegralValue;
        TEdit *EditScope1;
        TCheckBox *cbFindRoots;
        TCheckBox *cbToNegative;
        TEdit *EditIndex;
        TLabel *lbIndex;
        TCheckBox *cbGetIndex;
        TCheckBox *cbMutiConst;
        TCheckBox *cbCount;
        void __fastcall cbCheckPoly2Click(TObject *Sender);
        void __fastcall cbCheckValClick(TObject *Sender);
        void __fastcall cbIntegralValueClick(TObject *Sender);
        void __fastcall ButtonCalculateClick(TObject *Sender);
        void __fastcall cbGetIndexClick(TObject *Sender);
        void __fastcall cbMutiConstClick(TObject *Sender);
        
       
private:
int numPolynom2Watchers;
int numValWatchers;
AnsiString  ToAnsiStr(Polynom polynom);

// User declarations
public:		// User declarations
        __fastcall TPoltnomForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPoltnomForm *PoltnomForm;
//---------------------------------------------------------------------------
#endif
