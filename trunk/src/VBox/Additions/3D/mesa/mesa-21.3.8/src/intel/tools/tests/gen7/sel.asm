(+f0.0) sel(8)  g47<1>UD        g12<4>UD        g13<4>UD        { align16 1Q };
(-f0.0) sel(8)  g25<1>.xyUD     g13<4>.zwwwUD   0x40000000UD    { align16 1Q };
(+f0.0.any4h) sel(8) g30<1>UD   g13<4>UD        g12<4>UD        { align16 1Q };
(+f0.0.all4h) sel(8) g16<1>UD   g8<4>UD         g9<4>UD         { align16 1Q };
(+f0.0) sel(8)  g2<1>UD         g31<8,8,1>UD    g34<8,8,1>UD    { align1 1Q };
(+f0.0) sel(8)  g124<1>UD       g67<8,8,1>UD    0x3f800000UD    { align1 1Q };
(+f0.0) sel(16) g2<1>UD         g35<8,8,1>UD    g41<8,8,1>UD    { align1 1H };
(+f0.0) sel(16) g120<1>UD       g27<8,8,1>UD    0x3f800000UD    { align1 1H };
sel.ge(8)       g64<1>F         g9<8,8,1>F      0x0F  /* 0F */  { align1 1Q };
(-f0.0) sel(8)  g16<1>UD        g20<8,8,1>UD    0x00000000UD    { align1 1Q };
sel.ge(16)      g17<1>F         g3<8,8,1>F      0x0F  /* 0F */  { align1 1H };
(-f0.0) sel(16) g23<1>UD        g21<8,8,1>UD    0x00000000UD    { align1 1H };
sel.l(8)        g13<1>.xyzD     g6<0>.xyzzD     g5.4<0>.zD      { align16 1Q };
sel.ge(8)       g3<1>.yF        g7<4>.xF        0x0F  /* 0F */  { align16 1Q };
sel.l(8)        g11<1>.xF       g7<4>.wF        0x43000000F  /* 128F */ { align16 1Q };
(-f0.0.z) sel(8) g3<1>.zUD      g14<4>.xUD      0x00000000UD    { align16 1Q };
sel.l(8)        g14<1>UD        g6<0>UD         g6.4<0>UD       { align16 1Q };
(+f0.0.x) sel(8) g32<1>.xUD     g12<4>.yUD      0x41a80000UD    { align16 1Q };
(-f0.0.x) sel(8) g33<1>.xUD     g32<4>.xUD      0x41b80000UD    { align16 1Q };
sel.ge(8)       g2<1>F          (abs)g7<8,8,1>F (abs)g8<8,8,1>F { align1 1Q };
sel.ge(16)      g2<1>F          (abs)g10<8,8,1>F (abs)g12<8,8,1>F { align1 1H };
(+f0.0.x) sel(8) g25<1>.xUD     g23<4>.yUD      g23<4>.xUD      { align16 1Q };
sel.sat.l(8)    g116<1>F        g2<4>F          0x3f000000F  /* 0.5F */ { align16 1Q };
sel.l(8)        g13<1>.xF       g1<0>.wF        g1<0>.zF        { align16 1Q };
sel.ge(8)       g13<1>.xF       g1<0>.wF        g1<0>.zF        { align16 1Q };
(-f0.0.any4h) sel(8) g67<1>.xUD g63<4>.xUD      0x00000000UD    { align16 1Q };
(+f0.0.x) sel(8) g17<1>.xF      g5.4<0>.zF      -g5.4<0>.zF     { align16 1Q };
sel.l(8)        g124<1>F        g2.3<0,1,0>F    g2.2<0,1,0>F    { align1 1Q };
sel.l(16)       g120<1>F        g2.3<0,1,0>F    g2.2<0,1,0>F    { align1 1H };
sel.ge(8)       g13<1>.xyzD     g6<0>.xyzzD     g5.4<0>.zD      { align16 1Q };
sel.ge(8)       g13<1>.xyUD     g5.4<0>.zwwwUD  g6<0>.xyyyUD    { align16 1Q };
(+f0.0.any4h) sel(8) g17<1>.xUD g8<4>.xUD       0x00000001UD    { align16 1Q };
sel.ge(8)       g12<1>.xD       g5.4<0>.zD      -1D             { align16 1Q };
sel.l(8)        g14<1>.xD       g12<4>.xD       1D              { align16 1Q };
sel.l(8)        g3<1>UD         g2.1<0,1,0>UD   0x00000001UD    { align1 1Q };
sel.l(16)       g3<1>UD         g2.1<0,1,0>UD   0x00000001UD    { align1 1H };
sel.ge(8)       g4<1>D          g3<0,1,0>D      -252D           { align1 1Q };
sel.l(8)        g5<1>D          g4<8,8,1>D      254D            { align1 1Q };
sel.ge(16)      g4<1>D          g3<0,1,0>D      -252D           { align1 1H };
sel.l(16)       g6<1>D          g4<8,8,1>D      254D            { align1 1H };
sel.sat.l(8)    g116<1>F        g1<0>F          g3<4>F          { align16 1Q };
sel.l(8)        g6<1>F          g3<8,8,1>F      0x40400000F  /* 3F */ { align1 1Q };
sel.l(16)       g2<1>F          g20<8,8,1>F     0x40400000F  /* 3F */ { align1 1H };
(+f0.0) sel(8)  g28<1>.xyF      (abs)g6<0>.xyyyF g5.4<0>.zwwwF  { align16 1Q };
(+f0.0) sel(8)  g31<1>.xyUD     g10<4>.xyyyUD   0x3f800000UD    { align16 1Q };
(-f0.0) sel(8)  g38<1>.xyF      (abs)g35<4>.xyyyF 0x3f800000F  /* 1F */ { align16 1Q };
sel.l(8)        g13<1>.xUD      g11<4>.xUD      0x00000007UD    { align16 1Q };
(+f1.0) sel(4)  g17<1>.xUD      g15.4<4>.xUD    g15<4>.xUD      { align16 WE_all 1N };
(+f0.0) sel(8)  g57<1>F         (abs)g2.3<0,1,0>F g2<0,1,0>F    { align1 1Q };
(-f0.0) sel(8)  g29<1>F         (abs)g26<8,8,1>F 0x3f800000F  /* 1F */ { align1 1Q };
(+f0.0) sel(16) g8<1>F          (abs)g2.3<0,1,0>F g2<0,1,0>F    { align1 1H };
(-f0.0) sel(16) g55<1>F         (abs)g14<8,8,1>F 0x3f800000F  /* 1F */ { align1 1H };
(-f0.0.x) sel(8) g32<1>.xF      (abs)g29<4>.xF  0x3f800000F  /* 1F */ { align16 1Q };
sel.sat.ge(8)   g116<1>F        g25<4>F         0xbf800000F  /* -1F */ { align16 1Q };
sel.sat.l(8)    g46<1>F         g45<8,8,1>F     0x3f000000F  /* 0.5F */ { align1 1Q };
sel.sat.l(16)   g8<1>F          g83<8,8,1>F     0x3f000000F  /* 0.5F */ { align1 1H };
