
import /nfs/user/kjaffel/MG5_aMC_v2_7_3/HToZATo2L2B_200p00_50p00_ggH_TuneCP5_13TeV_pythia8/bin/internal/ufomodel
# Hadron input files 
import /nfs/user/kjaffel/MG5_aMC_v2_7_3/HToZATo2L2B_200p00_50p00_ggH_TuneCP5_13TeV_pythia8/Events/run_tb_0p50_decayed_2/tag_2_pythia8_events.hepmc as B1_tb-0p5 
import /nfs/user/kjaffel/MG5_aMC_v2_7_3/HToZATo2L2B_200p00_50p00_ggH_TuneCP5_13TeV_pythia8/Events/run2_tb_1p5_decayed_1/tag_1_pythia8_events.hepmc.gz as B1_tb-1p5
import /nfs/user/kjaffel/MG5_aMC_v2_7_3/HToZATo2L2B_200p00_50p00_ggH_TuneCP5_13TeV_pythia8/Events/run3_tb_4p5_decayed_1/tag_1_pythia8_events.hepmc.gz as B1_tb-4p5
import /nfs/user/kjaffel/MG5_aMC_v2_7_3/HToZATo2L2B_200p00_50p00_ggH_TuneCP5_13TeV_pythia8/Events/run4_tb8_decayed_1/tag_1_pythia8_events.hepmc.gz as B1_tb-8
import /nfs/user/kjaffel/MG5_aMC_v2_7_3/HToZATo2L2B_200p00_50p00_ggH_TuneCP5_13TeV_pythia8/Events/run5_tb20_decayed_1/tag_1_pythia8_events.hepmc.gz as B1_tb-20

# Parton input files
#import samples/ttbar_sl_1.lhe.gz as ttbar_SemiLeptonic
#import samples/ttbar_sl_2.lhe.gz as ttbar_SemiLeptonic
#import samples/ttbar_fh.lhe.gz as ttbar_FullyHadronic

## reconstructed object level
#import samples/mg5_zll.lhco as Drell_Yan
#import samples/mg5_ttbar2l.lhco as ttbar_FullyLeptonic
# for reco Only 
#set detector.fastsim.package = fastjet
#set detector.fastsim.algo = kt

set main.stacking_method = normalize2one
set main.lumi= 137.19   
# should be the cross section of your signal event -- 
# Total cross section: 6.953e-05 +- 6.5e-06 pb
#set Signal.xsection= 6.953e-05   

#set ttbar_SemiLeptonic.type = background
#set ttbar_FullyHadronic.type = background
#set Drell_Yan.type = background
#set ttbar_FullyLeptonic.type = background

#set ttbar_SemiLeptonic.backcolor = orange 
#set ttbar_FullyHadronic.backcolor = cyan
#set Drell_Yan.backcolor = bleu
#set ttbar_FullyLeptonic.backcolor = green

set B1_tb-0p5.linecolor = red
set B1_tb-0p5.linewidth = 3
set B1_tb-0p5.backcolor = none
set B1_tb-0p5.linestyle = dashed
set B1_tb-0p5.type = signal

set B1_tb-1p5.linecolor = green
set B1_tb-1p5.linewidth = 3
set B1_tb-1p5.backcolor = none
set B1_tb-1p5.linestyle = dashed
set B1_tb-1p5.type = signal

set B1_tb-4p5.linecolor = purple
set B1_tb-4p5.linewidth = 3
set B1_tb-4p5.backcolor = none
set B1_tb-4p5.linestyle = dashed
set B1_tb-4p5.type = signal

set B1_tb-8.linecolor = orange
set B1_tb-8.linewidth = 3
set B1_tb-8.backcolor = none
set B1_tb-8.linestyle = dashed
set B1_tb-8.type = signal

set B1_tb-20.linecolor = cyan
set B1_tb-20.linewidth = 3
set B1_tb-20.backcolor = none
set B1_tb-20.linestyle = dashed
set B1_tb-20.type = signal

define diele= e+ e- 
define dimu= mu+ mu-
define muel= mu+ e-
define elmu= e+ mu-
define jets= j
define bjets= b b~

# selections
#select 70.<M(diele)< 120.
#select 70.<M(dimu)< 120.

plot THT 40 0 500 [logY]
plot MET 40 0 150 [logY]
plot SQRTS 40 0 500 [logY]

plot N(jets) 10 0 10 [logY]
plot N(bjets) 10 0 10 [logY]

# h3 : pseudo-scalar A 
plot PT(h3[1]) 40 0 500 [logY interstate]
plot ETA(h3[1]) 40 -10 10 [logY interstate]
plot PT(b [1]) 40 0 500 [logY]
plot ETA(b [1]) 40 -10 10 [logY]
plot PT(b [2]) 40 0 500 [logY]
plot ETA(b [2]) 40 -10 10 [logY]
plot M(b[1] b[2]) 40 0 500 [logY]

# h2 : heavy neutral higgs
plot PT(h2[1]) 40 0 500 [logY interstate]
plot ETA(h2[1]) 40 -10 10 [logY interstate]
plot M(h3[1] z[1]) 40 0 500 [logY allstate]
plot DELTAR(h3[1],z[1]) 40 0 10 [logY allstate]

# Z Bosons 
plot PT(z[1]) 40 0 500 [logY interstate]
plot ETA(z[1]) 40 -10 10 [logY interstate]
plot M(z[1]) 40 0 500 [logY interstate]
# Z reconstructed from the leptons 
plot M(dimu)  50 70 120 [logY]
plot M(diele) 50 70 120 [logY]
plot PT(l-[1] l+[1]) 40 0 500 [logY]
plot M(l-[1] l+[1]) 40 0 500 [logY]
plot PT(l+[1]) 40 0 500 [logY]
plot PT(l-[1]) 40 0 500 [logY]
plot PT(l+[2]) 40 0 500 [logY]
plot PT(l-[2]) 40 0 500 [logY]
plot ETA(l+[1]) 40 -10 10 [logY]
plot ETA(l-[1]) 40 -10 10 [logY]
plot ETA(l+[2]) 40 -10 10 [logY]
plot ETA(l-[2]) 40 -10 10 [logY]

resubmit test_0321
