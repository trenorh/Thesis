//first we need to know which file to work with with. to do so, just ask for event numbers again
void demoRoot()
{ string events;
  events="1000000"; 
  // cout<<"How many events were there? ";
  // something about reading user input. idk look up later
  // string eventnumber;
  // eventnumber=TString(events);
  //now we need to attach the proper file to root.I think it'll be best to make a new string to make this easier
  string str1;
  str1 = "/home/cms-opendata/CMSSW_5_3_32/src/DoubleMu";
  string str4;
  str4 = "/home/cms-opendata/CMSSW_5_3_32/src/figures/DoubleMu";
  string str2;
  str2 = ".root";
  string str3;
  str3 =".pdf";
  string filepath;
  filepath= str1+events+str2;
  string imagepath;
  imagepath= str4+events+str3;
  //std::cout<< filepath;
  //printing the filepath just to be sure I didn't fuck up
  //commenting the next two lines out to see if they work manually, outside of script.
  TFile f1(TString(filepath));
  f1->cd("demo");
  GM_mass_log->Draw();
  c1.SetLogy();
  c1->SaveAs(TString(imagepath), ".pdf");
  
}
