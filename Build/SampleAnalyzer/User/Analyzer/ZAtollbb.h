#ifndef analysis_ZAtollbb_h
#define analysis_ZAtollbb_h

#include "SampleAnalyzer/Process/Analyzer/AnalyzerBase.h"
#include "SampleAnalyzer/Interfaces/root/RootMainHeaders.h"

namespace MA5
{
class ZAtollbb : public AnalyzerBase
{
  INIT_ANALYSIS(ZAtollbb,"MadAnalysis5job")

 public : 
  virtual MAbool Initialize(const MA5::Configuration& cfg,
                          const std::map<std::string,std::string>& parameters);
  virtual void Finalize(const SampleFormat& summary, const std::vector<SampleFormat>& files);
  virtual MAbool Execute(SampleFormat& sample, const EventFormat& event);

 private : 
  // Declaring particle containers
  std::vector<const MCParticleFormat*> _P_jetsPTorderingfinalstate_REG_;
  MAbool isP__jetsPTorderingfinalstate(const MCParticleFormat* part) const {
     if ( part==0 ) return false;
     if ( !PHYSICS->Id->IsFinalState(part) ) return false;
     if ( (part->pdgid()!=-4)&&(part->pdgid()!=-3)&&(part->pdgid()!=-2)&&(part->pdgid()!=-1)&&(part->pdgid()!=1)&&(part->pdgid()!=2)&&(part->pdgid()!=3)&&(part->pdgid()!=4)&&(part->pdgid()!=21) ) return false;
     return true; }
  std::vector<const MCParticleFormat*> _P_bjetsPTorderingfinalstate_REG_;
  MAbool isP__bjetsPTorderingfinalstate(const MCParticleFormat* part) const {
     if ( part==0 ) return false;
     if ( !PHYSICS->Id->IsFinalState(part) ) return false;
     if ( (part->pdgid()!=-5)&&(part->pdgid()!=5) ) return false;
     return true; }
  std::vector<const MCParticleFormat*> _P_h3_I1I_PTorderinginterstate_REG_;
  std::vector<const MCParticleFormat*> _P_b_I1I_PTorderingfinalstate_REG_;
  std::vector<const MCParticleFormat*> _P_b_I2I_PTorderingfinalstate_REG_;
  std::vector<const MCParticleFormat*> _P_h2_I1I_PTorderinginterstate_REG_;
  std::vector<const MCParticleFormat*> _P_h3_I1I_PTorderingallstate_REG_;
  std::vector<const MCParticleFormat*> _P_z_I1I_PTorderingallstate_REG_;
  std::vector<const MCParticleFormat*> _P_z_I1I_PTorderinginterstate_REG_;
  std::vector<const MCParticleFormat*> _P_dimuPTorderingfinalstate_REG_;
  MAbool isP__dimuPTorderingfinalstate(const MCParticleFormat* part) const {
     if ( part==0 ) return false;
     if ( !PHYSICS->Id->IsFinalState(part) ) return false;
     if ( (part->pdgid()!=-13)&&(part->pdgid()!=13) ) return false;
     return true; }
  std::vector<const MCParticleFormat*> _P_dielePTorderingfinalstate_REG_;
  MAbool isP__dielePTorderingfinalstate(const MCParticleFormat* part) const {
     if ( part==0 ) return false;
     if ( !PHYSICS->Id->IsFinalState(part) ) return false;
     if ( (part->pdgid()!=-11)&&(part->pdgid()!=11) ) return false;
     return true; }
  std::vector<const MCParticleFormat*> _P_l_p_I1I_PTorderingfinalstate_REG_;
  std::vector<const MCParticleFormat*> _P_l_m_I1I_PTorderingfinalstate_REG_;
  std::vector<const MCParticleFormat*> _P_l_p_I2I_PTorderingfinalstate_REG_;
  std::vector<const MCParticleFormat*> _P_l_m_I2I_PTorderingfinalstate_REG_;
  std::vector<const MCParticleFormat*> _P_h3PTorderinginterstate_REG_;
  MAbool isP__h3PTorderinginterstate(const MCParticleFormat* part) const {
     if ( part==0 ) return false;
     if ( !PHYSICS->Id->IsInterState(part) ) return false;
     if ( (part->pdgid()!=36) ) return false;
     return true; }
  std::vector<const MCParticleFormat*> _P_bPTorderingfinalstate_REG_;
  MAbool isP__bPTorderingfinalstate(const MCParticleFormat* part) const {
     if ( part==0 ) return false;
     if ( !PHYSICS->Id->IsFinalState(part) ) return false;
     if ( (part->pdgid()!=5) ) return false;
     return true; }
  std::vector<const MCParticleFormat*> _P_h2PTorderinginterstate_REG_;
  MAbool isP__h2PTorderinginterstate(const MCParticleFormat* part) const {
     if ( part==0 ) return false;
     if ( !PHYSICS->Id->IsInterState(part) ) return false;
     if ( (part->pdgid()!=35) ) return false;
     return true; }
  std::vector<const MCParticleFormat*> _P_h3PTorderingallstate_REG_;
  MAbool isP__h3PTorderingallstate(const MCParticleFormat* part) const {
     if ( part==0 ) return false;
     if ( (part->pdgid()!=36) ) return false;
     return true; }
  std::vector<const MCParticleFormat*> _P_zPTorderingallstate_REG_;
  MAbool isP__zPTorderingallstate(const MCParticleFormat* part) const {
     if ( part==0 ) return false;
     if ( (part->pdgid()!=23) ) return false;
     return true; }
  std::vector<const MCParticleFormat*> _P_zPTorderinginterstate_REG_;
  MAbool isP__zPTorderinginterstate(const MCParticleFormat* part) const {
     if ( part==0 ) return false;
     if ( !PHYSICS->Id->IsInterState(part) ) return false;
     if ( (part->pdgid()!=23) ) return false;
     return true; }
  std::vector<const MCParticleFormat*> _P_l_pPTorderingfinalstate_REG_;
  MAbool isP__l_pPTorderingfinalstate(const MCParticleFormat* part) const {
     if ( part==0 ) return false;
     if ( !PHYSICS->Id->IsFinalState(part) ) return false;
     if ( (part->pdgid()!=-13)&&(part->pdgid()!=-11) ) return false;
     return true; }
  std::vector<const MCParticleFormat*> _P_l_mPTorderingfinalstate_REG_;
  MAbool isP__l_mPTorderingfinalstate(const MCParticleFormat* part) const {
     if ( part==0 ) return false;
     if ( !PHYSICS->Id->IsFinalState(part) ) return false;
     if ( (part->pdgid()!=11)&&(part->pdgid()!=13) ) return false;
     return true; }
};
}

#endif
