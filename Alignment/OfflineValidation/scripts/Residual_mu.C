class Plots{

  public:
  Plots();

  void Legend(TString histoname1,TString histoname2,TString histoname3, TString histoname3, TH1F *histo1, TH1F *histo2, TH1F *histo3,TH1F *histo4);  
  void Save();
  
  float convert(float num);

};

void Plots::Plots()
{

gROOT->Reset();
gROOT->Clear();

gStyle->SetNdivisions(10);
gStyle->SetCanvasBorderMode(0); 
gStyle->SetPadBorderMode(1);
gStyle->SetOptTitle(1);
gStyle->SetStatFont(42);
gStyle->SetCanvasColor(10);
gStyle->SetPadColor(0);
gStyle->SetTitleFont(62,"xy");
gStyle->SetLabelFont(62,"xy");
gStyle->SetTitleFontSize(0.05);
gStyle->SetTitleSize(0.039,"xy");
gStyle->SetLabelSize(0.046,"xy");
// gStyle->SetTitleFillColor(0);
gStyle->SetHistFillStyle(1001);
gStyle->SetHistFillColor(0);
gStyle->SetHistLineStyle(1);
gStyle->SetHistLineWidth(2);
gStyle->SetHistLineColor(2);
gStyle->SetTitleXOffset(1.15);
gStyle->SetTitleYOffset(1.35);
gStyle->SetOptStat(1110);
gStyle->SetOptStat(kFALSE);
gStyle->SetOptFit(0111);
gStyle->SetStatH(0.1); 

TCanvas *c1 = new TCanvas("c1","c1",129,17,926,703);
c1->SetBorderSize(2);
c1->SetFrameFillColor(0);
c1->SetLogy(0);
c1->cd(); 

TFile *f[5];
TTree *MyTree[5];


f[0]= new TFile("ValidationMisalignedTracker_singlemu100_merged.root");
MyTree[0]=EffTracks;

f[1]=new TFile("../../SurveyLAS/singlemu/Misalignment_SurveyLASOnlyScenario_refitter_singlemu.root");
MyTree[1]=Tracks;
 
f[2]=new TFile("Misalignment_SurveyLASOnlyScenario_refitter_zmumu_singlemuSurveyLASCosmics.root");
MyTree[2]=Tracks;
 
f[3]=new TFile("../../singlemu_310607/Misalignment10.root");
MyTree[3]=Tracks;
 
f[4]=new TFile("../../singlemu_310607/Misalignment100.root");
MyTree[4]=Tracks;


////&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
/// EFFICIENCIES VS ETA ALIGNED
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
hframe = new TH2F("hframe","#Delta(p_{T})/p_{T}",100,-0.3,0.3,32,0.,0.16);
hframe->SetXTitle("#Delta(p_{T})/p_{T}");
hframe->SetYTitle("N. ev. /0.006");
hframe->Draw();


char histoname[128];
char name[128];
TH1F *Respt[5];

for(int i=0; i<5; i++){
  sprintf(name,"Respt[%d]",i);
  Respt[i] = new TH1F(name,name,100,-0.3,0.3);
  sprintf(histoname,"Respt[%d]",i);
  MyTree[i]->Project(histoname,"respt/pt","eff==1 && TrackID==13");

  cout << "Entries " << Respt[i]->GetEntries() <<endl;
  Respt[i]->Scale(1/Respt[i]->GetEntries());
  Respt[i]->SetTitle("#Delta(p_{T})/p_{T}");    
  Respt[i]->SetXTitle("#Delta(p_{T})/p_{T} ");
  Respt[i]->SetYTitle("arb. units");
  
  Respt[i]->SetLineColor(i+2);
  Respt[i]->SetLineStyle(i+1);
  Respt[i]->SetLineWidth(i+2);
  if (i==0) Respt[i]->Draw("same");
  else Respt[i]->Draw("same");
  //  c1->WaitPrimitive();
  c1->Update();
}

Legend("Respt[0]","Respt[1]","Respt[2]","Respt[3]","Respt[4]",Respt[0],Respt[1],Respt[2],Respt[3],Respt[4]);

c1->SaveAs("ResidualPt_mu.eps");
c1->SaveAs("ResidualPt_mu.gif");

gROOT->Reset();
gROOT->Clear();

delete c1;

}

void Plots::Legend(TString histoname1,TString histoname2,TString histoname3, TString histoname4, TString histoname5, TH1F *histo1, TH1F *histo2, TH1F *histo3, TH1F *histo4, TH1F *histo5)
{

TLegend *leg = new TLegend(0.31,0.74.,0.995,0.995); 
leg->SetTextAlign(32);
leg->SetTextColor(1);
leg->SetTextSize(0.033);
leg->SetFillColor(0);

char  label[128];
// sprintf(label,"perfect alignment;      mean = %1.3f, RMS = %1.3f",convert(histo1->GetMean()),convert(histo1->GetRMS()));
// leg->AddEntry(histoname1, label, "l");
// sprintf(label,"SurveyLAS alignment; mean = %1.3f, RMS = %1.3f",convert(histo2->GetMean()),convert(histo2->GetRMS()));
// leg->AddEntry(histoname2, label, "l");
// sprintf(label,"SurveyLASCosmics alignment; mean = %1.3f, RMS = %1.3f",convert(histo3->GetMean()),convert(histo3->GetRMS()));
// leg->AddEntry(histoname3, label, "l");
// sprintf(label,"10 pb-1 alignment;  mean = %1.3f, RMS = %1.3f",convert(histo4->GetMean()),convert(histo4->GetRMS()));
// leg->AddEntry(histoname4, label, "l");
// sprintf(label,"100 pb-1 alignment;  mean = %1.3f, RMS = %1.3f",convert(histo5->GetMean()),convert(histo5->GetRMS()));
// leg->AddEntry(histoname5, label, "l");

sprintf(label,"perfect; mean=%1.4f, RMS=%1.4f",(histo1->GetMean()),histo1->GetRMS());
leg->AddEntry(histoname1, label, "l");
sprintf(label,"SurveyLAS; mean=%1.4f, RMS=%1.4f",(histo2->GetMean()),histo2->GetRMS());
leg->AddEntry(histoname2, label, "l");
sprintf(label,"SurveyLASCosmics; mean=%1.4f, RMS=%1.4f",(histo3->GetMean()),histo3->GetRMS());
leg->AddEntry(histoname3, label, "l");
sprintf(label,"10 pb^{-1};  mean=%1.4f, RMS=%1.4f",(histo4->GetMean()),histo4->GetRMS());
leg->AddEntry(histoname4, label, "l");
sprintf(label,"100 pb^{-1};  mean=%1.4f, RMS=%1.4f",(histo5->GetMean()),histo5->GetRMS());
leg->AddEntry(histoname5, label, "l");

leg->Draw();

}

float Plots::convert(float num){
  int mean1 = num;
  float res = num - mean1;
  int res2 = res*1000;
  float res3 = res2*0.001;
  float mean2 = mean1 + res3;
                                                                                                                  
  float res4 = res - res3;
  int res5 = res4*10000;
                                                                                                                  
  if(res5>5)
    mean2 = mean2 + 0.001;
                                                                                                                  
  return mean2;
}
