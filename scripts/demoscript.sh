
#this is a script to run demoanalyzer_cfg.py
clear
cd ..
cd src
cmsenv
#as of now, the cmsenv line won't work and must be called before the script. 
cd Demo/DemoAnalyzer
read -p "How many events to analyze? "  eventnumber
#double quotes super neccesary for sed to work here
sed -i "22s,.*,process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32($eventnumber))," "demoanalyzer_cfg.py"
sed -i "74s,.*,fileName = cms.string('DoubleMu$eventnumber.root'),"  "demoanalyzer_cfg.py"
scram b
cd ../..
cmsRun Demo/DemoAnalyzer/demoanalyzer_cfg.py
#idea: make a C/root script and call it at the end of this script.
cd ../scripts
insertion=' events="'$eventnumber'";'
sed -i "4s, .*, $insertion ," "demoRoot.C"
root demoRoot.C

