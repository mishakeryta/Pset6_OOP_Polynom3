//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UnitMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPoltnomForm *PoltnomForm;

//---------------------------------------------------------------------------
__fastcall TPoltnomForm::TPoltnomForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPoltnomForm::cbCheckPoly2Click(TObject *Sender)
{
        TCheckBox* cbCheker = (TCheckBox*) Sender;
        if(cbCheker->Checked)
        {
                 ++numPolynom2Watchers;
        }
        else
        {
                 --numPolynom2Watchers;
        }
        if(numPolynom2Watchers)
        {
                 lbPolynom2->Visible = True;
                 EditA2->Visible = True;
                 EditB2->Visible = True;
                 EditC2->Visible = True;
                 lbSquareX2->Visible = True;
                 lbX2->Visible = True;
        }
        else
        {

                lbPolynom2->Visible = False;
                EditA2->Visible = False;
                EditB2->Visible = False;
                EditC2->Visible = False;
                lbSquareX2->Visible = False;
                lbX2->Visible = False;
        }
}
//---------------------------------------------------------------------------
void __fastcall TPoltnomForm::cbCheckValClick(TObject *Sender)
{
        TCheckBox* cbChecker =  (TCheckBox*)Sender;
        if(cbChecker->Checked)
        {
                ++numValWatchers;
        }
        else
        {
                --numValWatchers;
        }
        if(numValWatchers)
        {
                lbVal->Visible = True;
                EditVal->Visible = True;
        }
        else
        {
                lbVal->Visible = False;
                EditVal->Visible = False;
        }
}
//---------------------------------------------------------------------------
void __fastcall TPoltnomForm::cbIntegralValueClick(TObject *Sender)
{
        lbBoundaries->Visible = !lbBoundaries->Visible;
        EditScope1->Visible = !EditScope1->Visible;
        EditScope2->Visible = !EditScope2->Visible;

}
//---------------------------------------------------------------------------
void __fastcall TPoltnomForm::ButtonCalculateClick(TObject *Sender)
{
        reOutPut->Lines->Clear();
        Polynom polynom1(StrToFloat(EditA->Text),StrToFloat(EditB->Text),StrToFloat(EditC->Text));
        double val = 0;
        Polynom polynom2(0,0,0);
        if(numValWatchers)
        {
                val = StrToFloat(EditVal->Text);
        }
        if(numPolynom2Watchers)
        {
                polynom2.SetABC(StrToFloat(EditA2->Text),StrToFloat(EditB2->Text),StrToFloat(EditC2->Text));
        }
        int indexRow = 0;
        if(cbAddition->Checked)
        {
            reOutPut->Lines->Strings[indexRow] = reOutPut->Lines->Strings[indexRow] +  "(" + ToAnsiStr(polynom1)
            + ") + ("  + ToAnsiStr(polynom2) +  ") ="
            + ToAnsiStr(polynom1+polynom2) + ";\n";
            ++indexRow;
        }
        if(cbSubtraction->Checked)
        {
            reOutPut->Lines->Strings[indexRow]  = reOutPut->Lines->Strings[indexRow] + "(" + ToAnsiStr(polynom1 )
            + ") - ("  + ToAnsiStr(polynom2) +  ") ="
            + ToAnsiStr(polynom1-polynom2) + ";\n";
            ++indexRow;
        }
        if(cbValueInPoint->Checked)
        {
             reOutPut->Lines->Strings[indexRow] =   reOutPut->Lines->Strings[indexRow]
             + "Polylom1("+ FloatToStr(val) + ") = "
             + FloatToStr(polynom1(val)) + ";\n";
             ++indexRow;
        }
        if(cbDarivativValue->Checked)
        {
             reOutPut->Lines->Strings[indexRow] =   reOutPut->Lines->Strings[indexRow]
             + "Polylom1'("+ FloatToStr(val) + ") = "
             + FloatToStr(polynom1.FindDerivativeValue(val)) + ";\n";
             ++indexRow;
        }
        if(cbIntegralValue->Checked)
        {
               double bound1 = StrToFloat(EditScope1->Text),
                bound2 = StrToFloat(EditScope2->Text);
                if(bound1>bound2)
                {
                        double tmp = bound1;
                        bound1 = bound2;
                        bound2 = tmp;
                }
                reOutPut->Lines->Strings[indexRow] =  reOutPut->Lines->Strings[indexRow]
                 + "IntegralOfPolynom1("+FloatToStr(bound1) + ";" + FloatToStr(bound2) + ") = "
                 + FloatToStr(polynom1.FindIntegralValue(bound1,bound2)) +  ";\n";
        }
        if(cbFindRoots->Checked)
        {
                double root1 = 0 ,root2 = 0;
                reOutPut->Lines->Strings[indexRow] = reOutPut->Lines->Strings[indexRow]
                + ToAnsiStr(polynom1) +  " = 0 ;\n";
                ++indexRow;
                switch(polynom1.FindRoots(root1,root2))
                {
                        case(1):
                        reOutPut->Lines->Strings[indexRow] = reOutPut->Lines->Strings[indexRow]
                        + "root1 = " + FloatToStr(root1) + " , " +  "root2 = " + FloatToStr(root2)
                        +";\n";
                        break;
                        case(0):
                        reOutPut->Lines->Strings[indexRow] = reOutPut->Lines->Strings[indexRow]
                        +"Some error occurs!!!\n";
                        break;
                        case(-1):
                        reOutPut->Lines->Strings[indexRow] = reOutPut->Lines->Strings[indexRow] +
                        "D < 0;\n";
                        break;
                }
                ++indexRow;
        }
        if(cbToNegative->Checked)
        {
                reOutPut->Lines->Strings[indexRow] = reOutPut->Lines->Strings[indexRow]
                + "!(" + ToAnsiStr(polynom1) +") = " +ToAnsiStr(!polynom1)+ ";\n";
                ++indexRow;
        }
        if(cbGetIndex->Checked)
        {
                try
                {
                        int index = StrToInt(EditIndex->Text);
                        reOutPut->Lines->Strings[indexRow] = reOutPut->Lines->Strings[indexRow]
                        + "K of polrnom1 with Index " + index + " = " + polynom1[index];
                        ++indexRow;
                }
                catch (int e)
                {
                        ShowMessage("I  dont so index\n");
                }
                catch(...)
                {
                        throw;
                }

         }
         if(cbMutiConst->Checked)
         {
                 reOutPut->Lines->Strings[indexRow] = reOutPut->Lines->Strings[indexRow]
                 + FloatToStr(val)+"*(" + ToAnsiStr(polynom1) +") = " + ToAnsiStr(val *polynom1)
                 + ";\n";
                 ++indexRow;
         }
         if(cbCount->Checked)
         {
                reOutPut->Lines->Strings[indexRow] = reOutPut->Lines->Strings[indexRow]
                + "Num of object :" + IntToStr(Polynom::GetNumOfObj()) +";\n";
                ++indexRow;
         }
         

}
AnsiString  TPoltnomForm::ToAnsiStr(Polynom polynom)
{
        AnsiString result = "";
        std::string str = "";
        str << polynom ;
        for(int i =0;i<str.length();++i)
        {
                result += str[i];
        }
        return result;
}
//---------------------------------------------------------------------------


void __fastcall TPoltnomForm::cbGetIndexClick(TObject *Sender)
{
        lbIndex->Visible = !lbIndex->Visible;
        EditIndex->Visible = !EditIndex->Visible;       
}
//---------------------------------------------------------------------------

void __fastcall TPoltnomForm::cbMutiConstClick(TObject *Sender)
{
TCheckBox* cbChecker =  (TCheckBox*)Sender;
        if(cbChecker->Checked)
        {
                ++numValWatchers;
        }
        else
        {
                --numValWatchers;
        }
        if(numValWatchers)
        {
                lbVal->Visible = True;
                EditVal->Visible = True;
        }
        else
        {
                lbVal->Visible = False;
                EditVal->Visible = False;
        }
}
//---------------------------------------------------------------------------

