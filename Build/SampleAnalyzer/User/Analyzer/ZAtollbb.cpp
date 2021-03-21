#include "SampleAnalyzer/User/Analyzer/ZAtollbb.h"
using namespace MA5;

MAbool ZAtollbb::Initialize(const MA5::Configuration& cfg,
                      const std::map<std::string,std::string>& parameters)
{
  // Initializing PhysicsService for MC
  PHYSICS->mcConfig().Reset();

  // definition of the multiparticle "hadronic"
  PHYSICS->mcConfig().AddHadronicId(-5);
  PHYSICS->mcConfig().AddHadronicId(-4);
  PHYSICS->mcConfig().AddHadronicId(-3);
  PHYSICS->mcConfig().AddHadronicId(-2);
  PHYSICS->mcConfig().AddHadronicId(-1);
  PHYSICS->mcConfig().AddHadronicId(1);
  PHYSICS->mcConfig().AddHadronicId(2);
  PHYSICS->mcConfig().AddHadronicId(3);
  PHYSICS->mcConfig().AddHadronicId(4);
  PHYSICS->mcConfig().AddHadronicId(5);
  PHYSICS->mcConfig().AddHadronicId(21);

  // definition of the multiparticle "invisible"
  PHYSICS->mcConfig().AddInvisibleId(-9000002);
  PHYSICS->mcConfig().AddInvisibleId(-9000001);
  PHYSICS->mcConfig().AddInvisibleId(-16);
  PHYSICS->mcConfig().AddInvisibleId(-14);
  PHYSICS->mcConfig().AddInvisibleId(-12);
  PHYSICS->mcConfig().AddInvisibleId(12);
  PHYSICS->mcConfig().AddInvisibleId(14);
  PHYSICS->mcConfig().AddInvisibleId(16);
  PHYSICS->mcConfig().AddInvisibleId(9000001);
  PHYSICS->mcConfig().AddInvisibleId(9000002);

  // ===== Signal region ===== //
  Manager()->AddRegionSelection("myregion");

  // ===== Selections ===== //

  // ===== Histograms ===== //
  Manager()->AddHisto("1_THT", 40,0.0,500.0);
  Manager()->AddHisto("2_MET", 40,0.0,150.0);
  Manager()->AddHisto("3_SQRTS", 40,0.0,500.0);
  Manager()->AddHisto("4_N", 10,0.0,10.0);
  Manager()->AddHisto("5_N", 10,0.0,10.0);
  Manager()->AddHisto("6_PT", 40,0.0,500.0);
  Manager()->AddHisto("7_ETA", 40,-10.0,10.0);
  Manager()->AddHisto("8_PT", 40,0.0,500.0);
  Manager()->AddHisto("9_ETA", 40,-10.0,10.0);
  Manager()->AddHisto("10_PT", 40,0.0,500.0);
  Manager()->AddHisto("11_ETA", 40,-10.0,10.0);
  Manager()->AddHisto("12_M", 40,0.0,500.0);
  Manager()->AddHisto("13_PT", 40,0.0,500.0);
  Manager()->AddHisto("14_ETA", 40,-10.0,10.0);
  Manager()->AddHisto("15_M", 40,0.0,500.0);
  Manager()->AddHisto("16_DELTAR", 40,0.0,10.0);
  Manager()->AddHisto("17_PT", 40,0.0,500.0);
  Manager()->AddHisto("18_ETA", 40,-10.0,10.0);
  Manager()->AddHisto("19_M", 40,0.0,500.0);
  Manager()->AddHisto("20_M", 50,70.0,120.0);
  Manager()->AddHisto("21_M", 50,70.0,120.0);
  Manager()->AddHisto("22_PT", 40,0.0,500.0);
  Manager()->AddHisto("23_M", 40,0.0,500.0);
  Manager()->AddHisto("24_PT", 40,0.0,500.0);
  Manager()->AddHisto("25_PT", 40,0.0,500.0);
  Manager()->AddHisto("26_PT", 40,0.0,500.0);
  Manager()->AddHisto("27_PT", 40,0.0,500.0);
  Manager()->AddHisto("28_ETA", 40,-10.0,10.0);
  Manager()->AddHisto("29_ETA", 40,-10.0,10.0);
  Manager()->AddHisto("30_ETA", 40,-10.0,10.0);
  Manager()->AddHisto("31_ETA", 40,-10.0,10.0);

  // No problem during initialization
  return true;
}

MAbool ZAtollbb::Execute(SampleFormat& sample, const EventFormat& event)
{
  MAfloat32 __event_weight__ = 1.0;
  if (weighted_events_ && event.mc()!=0) __event_weight__ = event.mc()->weight();

  if (sample.mc()!=0) sample.mc()->addWeightedEvents(__event_weight__);
  Manager()->InitializeForNewEvent(__event_weight__);

  // Clearing particle containers
  {
      _P_jetsPTorderingfinalstate_REG_.clear();
      _P_bjetsPTorderingfinalstate_REG_.clear();
      _P_h3_I1I_PTorderinginterstate_REG_.clear();
      _P_b_I1I_PTorderingfinalstate_REG_.clear();
      _P_b_I2I_PTorderingfinalstate_REG_.clear();
      _P_h2_I1I_PTorderinginterstate_REG_.clear();
      _P_h3_I1I_PTorderingallstate_REG_.clear();
      _P_z_I1I_PTorderingallstate_REG_.clear();
      _P_z_I1I_PTorderinginterstate_REG_.clear();
      _P_dimuPTorderingfinalstate_REG_.clear();
      _P_dielePTorderingfinalstate_REG_.clear();
      _P_l_p_I1I_PTorderingfinalstate_REG_.clear();
      _P_l_m_I1I_PTorderingfinalstate_REG_.clear();
      _P_l_p_I2I_PTorderingfinalstate_REG_.clear();
      _P_l_m_I2I_PTorderingfinalstate_REG_.clear();
      _P_h3PTorderinginterstate_REG_.clear();
      _P_bPTorderingfinalstate_REG_.clear();
      _P_h2PTorderinginterstate_REG_.clear();
      _P_h3PTorderingallstate_REG_.clear();
      _P_zPTorderingallstate_REG_.clear();
      _P_zPTorderinginterstate_REG_.clear();
      _P_l_pPTorderingfinalstate_REG_.clear();
      _P_l_mPTorderingfinalstate_REG_.clear();
  }

  // Filling particle containers
  {
    for (MAuint32 i=0;i<event.mc()->particles().size();i++)
    {
      if (isP__jetsPTorderingfinalstate((&(event.mc()->particles()[i])))) _P_jetsPTorderingfinalstate_REG_.push_back(&(event.mc()->particles()[i]));
      if (isP__bjetsPTorderingfinalstate((&(event.mc()->particles()[i])))) _P_bjetsPTorderingfinalstate_REG_.push_back(&(event.mc()->particles()[i]));
      if (isP__dimuPTorderingfinalstate((&(event.mc()->particles()[i])))) _P_dimuPTorderingfinalstate_REG_.push_back(&(event.mc()->particles()[i]));
      if (isP__dielePTorderingfinalstate((&(event.mc()->particles()[i])))) _P_dielePTorderingfinalstate_REG_.push_back(&(event.mc()->particles()[i]));
      if (isP__h3PTorderinginterstate((&(event.mc()->particles()[i])))) _P_h3PTorderinginterstate_REG_.push_back(&(event.mc()->particles()[i]));
      if (isP__bPTorderingfinalstate((&(event.mc()->particles()[i])))) _P_bPTorderingfinalstate_REG_.push_back(&(event.mc()->particles()[i]));
      if (isP__h2PTorderinginterstate((&(event.mc()->particles()[i])))) _P_h2PTorderinginterstate_REG_.push_back(&(event.mc()->particles()[i]));
      if (isP__h3PTorderingallstate((&(event.mc()->particles()[i])))) _P_h3PTorderingallstate_REG_.push_back(&(event.mc()->particles()[i]));
      if (isP__zPTorderingallstate((&(event.mc()->particles()[i])))) _P_zPTorderingallstate_REG_.push_back(&(event.mc()->particles()[i]));
      if (isP__zPTorderinginterstate((&(event.mc()->particles()[i])))) _P_zPTorderinginterstate_REG_.push_back(&(event.mc()->particles()[i]));
      if (isP__l_pPTorderingfinalstate((&(event.mc()->particles()[i])))) _P_l_pPTorderingfinalstate_REG_.push_back(&(event.mc()->particles()[i]));
      if (isP__l_mPTorderingfinalstate((&(event.mc()->particles()[i])))) _P_l_mPTorderingfinalstate_REG_.push_back(&(event.mc()->particles()[i]));
    }
  }

  // Sorting particles
  // Sorting particle collection according to PTordering
  // for getting 1th particle
  _P_h3_I1I_PTorderinginterstate_REG_=SORTER->rankFilter(_P_h3PTorderinginterstate_REG_,1,PTordering);

  // Sorting particle collection according to PTordering
  // for getting 1th particle
  _P_b_I1I_PTorderingfinalstate_REG_=SORTER->rankFilter(_P_bPTorderingfinalstate_REG_,1,PTordering);

  // Sorting particle collection according to PTordering
  // for getting 2th particle
  _P_b_I2I_PTorderingfinalstate_REG_=SORTER->rankFilter(_P_bPTorderingfinalstate_REG_,2,PTordering);

  // Sorting particle collection according to PTordering
  // for getting 1th particle
  _P_h2_I1I_PTorderinginterstate_REG_=SORTER->rankFilter(_P_h2PTorderinginterstate_REG_,1,PTordering);

  // Sorting particle collection according to PTordering
  // for getting 1th particle
  _P_h3_I1I_PTorderingallstate_REG_=SORTER->rankFilter(_P_h3PTorderingallstate_REG_,1,PTordering);

  // Sorting particle collection according to PTordering
  // for getting 1th particle
  _P_z_I1I_PTorderingallstate_REG_=SORTER->rankFilter(_P_zPTorderingallstate_REG_,1,PTordering);

  // Sorting particle collection according to PTordering
  // for getting 1th particle
  _P_z_I1I_PTorderinginterstate_REG_=SORTER->rankFilter(_P_zPTorderinginterstate_REG_,1,PTordering);

  // Sorting particle collection according to PTordering
  // for getting 1th particle
  _P_l_p_I1I_PTorderingfinalstate_REG_=SORTER->rankFilter(_P_l_pPTorderingfinalstate_REG_,1,PTordering);

  // Sorting particle collection according to PTordering
  // for getting 1th particle
  _P_l_m_I1I_PTorderingfinalstate_REG_=SORTER->rankFilter(_P_l_mPTorderingfinalstate_REG_,1,PTordering);

  // Sorting particle collection according to PTordering
  // for getting 2th particle
  _P_l_p_I2I_PTorderingfinalstate_REG_=SORTER->rankFilter(_P_l_pPTorderingfinalstate_REG_,2,PTordering);

  // Sorting particle collection according to PTordering
  // for getting 2th particle
  _P_l_m_I2I_PTorderingfinalstate_REG_=SORTER->rankFilter(_P_l_mPTorderingfinalstate_REG_,2,PTordering);

  // Histogram number 1
  //   * Plot: THT
  {
    Manager()->FillHisto("1_THT", PHYSICS->Transverse->EventTHT(event.mc()));
  }

  // Histogram number 2
  //   * Plot: MET
  {
    Manager()->FillHisto("2_MET", PHYSICS->Transverse->EventMET(event.mc()));
  }

  // Histogram number 3
  //   * Plot: SQRTS
  {
    Manager()->FillHisto("3_SQRTS", PHYSICS->SqrtS(event.mc()));
  }

  // Histogram number 4
  //   * Plot: N ( jets ) 
  {
  {
    unsigned int Ncounter=0;
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_jetsPTorderingfinalstate_REG_.size();ind[0]++)
    {
      Ncounter++;
    }
        Manager()->FillHisto("4_N", Ncounter);
  }
  }

  // Histogram number 5
  //   * Plot: N ( bjets ) 
  {
  {
    unsigned int Ncounter=0;
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_bjetsPTorderingfinalstate_REG_.size();ind[0]++)
    {
      Ncounter++;
    }
        Manager()->FillHisto("5_N", Ncounter);
  }
  }

  // Histogram number 6
  //   * Plot: PT ( h3[1] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_h3_I1I_PTorderinginterstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("6_PT", _P_h3_I1I_PTorderinginterstate_REG_[ind[0]]->pt());
    }
  }
  }

  // Histogram number 7
  //   * Plot: ETA ( h3[1] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_h3_I1I_PTorderinginterstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("7_ETA", _P_h3_I1I_PTorderinginterstate_REG_[ind[0]]->eta());
    }
  }
  }

  // Histogram number 8
  //   * Plot: PT ( b[1] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_b_I1I_PTorderingfinalstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("8_PT", _P_b_I1I_PTorderingfinalstate_REG_[ind[0]]->pt());
    }
  }
  }

  // Histogram number 9
  //   * Plot: ETA ( b[1] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_b_I1I_PTorderingfinalstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("9_ETA", _P_b_I1I_PTorderingfinalstate_REG_[ind[0]]->eta());
    }
  }
  }

  // Histogram number 10
  //   * Plot: PT ( b[2] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_b_I2I_PTorderingfinalstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("10_PT", _P_b_I2I_PTorderingfinalstate_REG_[ind[0]]->pt());
    }
  }
  }

  // Histogram number 11
  //   * Plot: ETA ( b[2] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_b_I2I_PTorderingfinalstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("11_ETA", _P_b_I2I_PTorderingfinalstate_REG_[ind[0]]->eta());
    }
  }
  }

  // Histogram number 12
  //   * Plot: M ( b[1] b[2] ) 
  {
  {
    MAuint32 ind[2];
    std::vector<std::set<const MCParticleFormat*> > combis;
    for (ind[0]=0;ind[0]<_P_b_I1I_PTorderingfinalstate_REG_.size();ind[0]++)
    {
    for (ind[1]=0;ind[1]<_P_b_I2I_PTorderingfinalstate_REG_.size();ind[1]++)
    {
    if (_P_b_I2I_PTorderingfinalstate_REG_[ind[1]]==_P_b_I1I_PTorderingfinalstate_REG_[ind[0]]) continue;

    // Checking if consistent combination
    std::set<const MCParticleFormat*> mycombi;
    for (MAuint32 i=0;i<2;i++)
    {
      mycombi.insert(_P_b_I1I_PTorderingfinalstate_REG_[ind[i]]);
      mycombi.insert(_P_b_I2I_PTorderingfinalstate_REG_[ind[i]]);
    }
    MAbool matched=false;
    for (MAuint32 i=0;i<combis.size();i++)
      if (combis[i]==mycombi) {matched=true; break;}
    if (matched) continue;
    else combis.push_back(mycombi);

    ParticleBaseFormat q;
    q+=_P_b_I1I_PTorderingfinalstate_REG_[ind[0]]->momentum();
    q+=_P_b_I2I_PTorderingfinalstate_REG_[ind[1]]->momentum();
      Manager()->FillHisto("12_M", q.m());
    }
    }
  }
  }

  // Histogram number 13
  //   * Plot: PT ( h2[1] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_h2_I1I_PTorderinginterstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("13_PT", _P_h2_I1I_PTorderinginterstate_REG_[ind[0]]->pt());
    }
  }
  }

  // Histogram number 14
  //   * Plot: ETA ( h2[1] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_h2_I1I_PTorderinginterstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("14_ETA", _P_h2_I1I_PTorderinginterstate_REG_[ind[0]]->eta());
    }
  }
  }

  // Histogram number 15
  //   * Plot: M ( h3[1] z[1] ) 
  {
  {
    MAuint32 ind[2];
    for (ind[0]=0;ind[0]<_P_h3_I1I_PTorderingallstate_REG_.size();ind[0]++)
    {
    for (ind[1]=0;ind[1]<_P_z_I1I_PTorderingallstate_REG_.size();ind[1]++)
    {
    ParticleBaseFormat q;
    q+=_P_h3_I1I_PTorderingallstate_REG_[ind[0]]->momentum();
    q+=_P_z_I1I_PTorderingallstate_REG_[ind[1]]->momentum();
      Manager()->FillHisto("15_M", q.m());
    }
    }
  }
  }

  // Histogram number 16
  //   * Plot: DELTAR ( h3[1] , z[1] ) 
  {
  {
    MAuint32 a[1];
    for (a[0]=0;a[0]<_P_h3_I1I_PTorderingallstate_REG_.size();a[0]++)
    {
    MAuint32 b[1];
    for (b[0]=0;b[0]<_P_z_I1I_PTorderingallstate_REG_.size();b[0]++)
    {
      Manager()->FillHisto("16_DELTAR", _P_h3_I1I_PTorderingallstate_REG_[a[0]]->dr(_P_z_I1I_PTorderingallstate_REG_[b[0]]));
    }
    }
  }
  }

  // Histogram number 17
  //   * Plot: PT ( z[1] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_z_I1I_PTorderinginterstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("17_PT", _P_z_I1I_PTorderinginterstate_REG_[ind[0]]->pt());
    }
  }
  }

  // Histogram number 18
  //   * Plot: ETA ( z[1] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_z_I1I_PTorderinginterstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("18_ETA", _P_z_I1I_PTorderinginterstate_REG_[ind[0]]->eta());
    }
  }
  }

  // Histogram number 19
  //   * Plot: M ( z[1] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_z_I1I_PTorderinginterstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("19_M", _P_z_I1I_PTorderinginterstate_REG_[ind[0]]->m());
    }
  }
  }

  // Histogram number 20
  //   * Plot: M ( dimu ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_dimuPTorderingfinalstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("20_M", _P_dimuPTorderingfinalstate_REG_[ind[0]]->m());
    }
  }
  }

  // Histogram number 21
  //   * Plot: M ( diele ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_dielePTorderingfinalstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("21_M", _P_dielePTorderingfinalstate_REG_[ind[0]]->m());
    }
  }
  }

  // Histogram number 22
  //   * Plot: PT ( l+[1] l-[1] ) 
  {
  {
    MAuint32 ind[2];
    for (ind[0]=0;ind[0]<_P_l_p_I1I_PTorderingfinalstate_REG_.size();ind[0]++)
    {
    for (ind[1]=0;ind[1]<_P_l_m_I1I_PTorderingfinalstate_REG_.size();ind[1]++)
    {
    ParticleBaseFormat q;
    q+=_P_l_p_I1I_PTorderingfinalstate_REG_[ind[0]]->momentum();
    q+=_P_l_m_I1I_PTorderingfinalstate_REG_[ind[1]]->momentum();
      Manager()->FillHisto("22_PT", q.pt());
    }
    }
  }
  }

  // Histogram number 23
  //   * Plot: M ( l+[1] l-[1] ) 
  {
  {
    MAuint32 ind[2];
    for (ind[0]=0;ind[0]<_P_l_p_I1I_PTorderingfinalstate_REG_.size();ind[0]++)
    {
    for (ind[1]=0;ind[1]<_P_l_m_I1I_PTorderingfinalstate_REG_.size();ind[1]++)
    {
    ParticleBaseFormat q;
    q+=_P_l_p_I1I_PTorderingfinalstate_REG_[ind[0]]->momentum();
    q+=_P_l_m_I1I_PTorderingfinalstate_REG_[ind[1]]->momentum();
      Manager()->FillHisto("23_M", q.m());
    }
    }
  }
  }

  // Histogram number 24
  //   * Plot: PT ( l+[1] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_l_p_I1I_PTorderingfinalstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("24_PT", _P_l_p_I1I_PTorderingfinalstate_REG_[ind[0]]->pt());
    }
  }
  }

  // Histogram number 25
  //   * Plot: PT ( l-[1] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_l_m_I1I_PTorderingfinalstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("25_PT", _P_l_m_I1I_PTorderingfinalstate_REG_[ind[0]]->pt());
    }
  }
  }

  // Histogram number 26
  //   * Plot: PT ( l+[2] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_l_p_I2I_PTorderingfinalstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("26_PT", _P_l_p_I2I_PTorderingfinalstate_REG_[ind[0]]->pt());
    }
  }
  }

  // Histogram number 27
  //   * Plot: PT ( l-[2] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_l_m_I2I_PTorderingfinalstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("27_PT", _P_l_m_I2I_PTorderingfinalstate_REG_[ind[0]]->pt());
    }
  }
  }

  // Histogram number 28
  //   * Plot: ETA ( l+[1] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_l_p_I1I_PTorderingfinalstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("28_ETA", _P_l_p_I1I_PTorderingfinalstate_REG_[ind[0]]->eta());
    }
  }
  }

  // Histogram number 29
  //   * Plot: ETA ( l-[1] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_l_m_I1I_PTorderingfinalstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("29_ETA", _P_l_m_I1I_PTorderingfinalstate_REG_[ind[0]]->eta());
    }
  }
  }

  // Histogram number 30
  //   * Plot: ETA ( l+[2] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_l_p_I2I_PTorderingfinalstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("30_ETA", _P_l_p_I2I_PTorderingfinalstate_REG_[ind[0]]->eta());
    }
  }
  }

  // Histogram number 31
  //   * Plot: ETA ( l-[2] ) 
  {
  {
    MAuint32 ind[1];
    for (ind[0]=0;ind[0]<_P_l_m_I2I_PTorderingfinalstate_REG_.size();ind[0]++)
    {
      Manager()->FillHisto("31_ETA", _P_l_m_I2I_PTorderingfinalstate_REG_[ind[0]]->eta());
    }
  }
  }

  return true;
}

void ZAtollbb::Finalize(const SampleFormat& summary, const std::vector<SampleFormat>& files)
{
}
