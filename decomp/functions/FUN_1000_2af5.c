/* 1000:2af5 */

/* WARNING: Instruction at (ram,0x00012cda) overlaps instruction at (ram,0x00012cd8)
    */
/* WARNING: Control flow encountered bad instruction data */

uint FUN_1000_2af5(undefined2 param_1,undefined2 param_2,undefined4 param_3)

{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar5;
  byte *pbVar6;
  byte bVar7;
  char cVar8;
  uint in_AX;
  int iVar9;
  uint uVar10;
  undefined2 uVar11;
  byte bVar13;
  uint uVar12;
  char extraout_AH;
  uint in_CX;
  byte bVar14;
  byte *in_EDX;
  byte *in_BX;
  byte *pbVar15;
  uint unaff_BP;
  byte *unaff_SI;
  uint *puVar16;
  uint *puVar17;
  byte *unaff_DI;
  undefined2 uVar18;
  int unaff_SS;
  undefined2 unaff_DS;
  bool bVar19;
  bool bVar20;
  undefined1 uVar21;
  char cVar22;
  undefined1 uStackY_7;
  undefined1 uVar23;
  int iStack_2;
  uint uVar4;
  
  bVar13 = 0;
  do {
    pbVar6 = *(byte **)(unaff_SI + 0x13);
    uVar18 = (undefined2)((ulong)pbVar6 >> 0x10);
    unaff_SI = (byte *)pbVar6;
    bVar7 = (byte)in_AX;
    bVar14 = (byte)in_EDX;
    cVar8 = (char)((uint)in_BX >> 8);
    if ((bVar7 < (byte)((ulong)in_EDX >> 8)) || (bVar14 <= bVar7)) {
      bVar7 = bVar7 - cVar8;
      in_AX = (uint)bVar7;
      if (bVar7 < (byte)in_BX) {
        iStack_2 = 0x33c2;
        uVar12 = (uint)bVar7;
        puVar17 = (uint *)*(undefined2 *)(uVar12 * 2 + 0x12ef);
        pbVar1 = in_BX + (int)puVar17;
        *pbVar1 = *pbVar1 + bVar14 + CARRY2(uVar12,uVar12);
        uVar23 = (undefined1)((ulong)pbVar6 >> 0x10);
        puVar16 = puVar17;
        if (*pbVar1 == 0) {
          *(byte *)((int)puVar17 + 0x43) = *(byte *)((int)puVar17 + 0x43);
          *(byte **)(byte *)(unaff_BP + (int)puVar17) =
               unaff_DI + *(int *)(byte *)(unaff_BP + (int)puVar17);
          puVar2 = puVar17;
          *(byte *)puVar2 = (byte)*puVar2 + cVar8;
          if (((byte)*puVar2 == 0) || (*(int *)0x347e == 0)) {
            FUN_1000_4b3d(uVar23);
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          func_0x0001a53d();
          cVar22 = (char)in_EDX;
          bVar7 = (char)((ulong)in_EDX >> 8) + 1;
          in_EDX = (byte *)CONCAT22((int)((ulong)in_EDX >> 0x10),
                                    (byte *)CONCAT11(bVar7 * '\x10',cVar22));
          cVar8 = unaff_DI[-0x2d81] + bVar7 + bVar7;
          if (CARRY1(unaff_DI[-0x2d81] + bVar7,bVar7)) {
            cVar8 = -1;
          }
          uVar12 = CONCAT11(bVar7,cVar8) & 0xd222;
          if (uVar12 == 0) {
            pbVar6 = unaff_DI;
            unaff_DI = unaff_DI + (uint)bVar13 * -2 + 1;
            *(byte *)(unaff_BP + (int)puVar17) =
                 *(byte *)(unaff_BP + (int)puVar17) + cVar22 + (*pbVar6 != 0);
            bVar19 = true;
            uVar11 = func_0x0001af11();
            if (!bVar19) {
              uVar12 = CONCAT11(100,(char)uVar11);
              goto code_r0x00012b9b;
            }
          }
          else {
code_r0x00012b9b:
            in_BX = (byte *)0x410;
            bVar7 = (char)uVar12 + 4;
            pbVar15 = unaff_DI + (uint)bVar13 * -2 + 1;
            *unaff_DI = bVar7;
            unaff_DI = pbVar15 + (uint)bVar13 * -2 + 1;
            uVar11 = CONCAT11((char)(uVar12 >> 8),((char)uVar12 + '|') - (bVar7 < *pbVar15));
            if (unaff_DI[-0x2d81] < 200) goto LAB_1000_2c73;
          }
          puVar17 = *(uint **)(unaff_DI + -0x1b82);
          bVar19 = false;
          puVar16 = puVar17;
          if (puVar17 == (uint *)0x0) {
            uVar21 = 0xb7;
            uVar11 = func_0x0001a512();
            if (!bVar19) {
              in_CX = CONCAT11((char)(in_CX >> 8),0x30);
              uVar11 = CONCAT11((char)(((uint)unaff_DI >> 1) / 0x30),
                                (char)(((uint)unaff_DI >> 1) % 0x30));
              *(undefined2 *)0x2 = uVar11;
              *(undefined2 *)0x4 = unaff_DI;
              *(undefined2 *)0x8 = uVar11;
              *(undefined1 *)0x0 = 0;
              *(undefined1 *)0x1 = 6;
              (unaff_DI + -0x1b82)[0] = 0;
              (unaff_DI + -0x1b82)[1] = 0;
              *(undefined1 *)0xa = 1;
              LOCK();
              bVar13 = unaff_DI[-0x2d81];
              unaff_DI[-0x2d81] = 1;
              UNLOCK();
              iVar9 = bVar13 - 1;
              *(int *)0x6 = iVar9;
              in_BX = (byte *)CONCAT11(uVar21,uStackY_7);
              *(byte *)0x0 = *(byte *)0x0 ^ 0x30;
              *(undefined1 *)0xc = (char)iVar9;
              goto LAB_1000_2c73;
            }
            *in_EDX = *in_EDX ^ (byte)in_CX;
          }
          pbVar15 = (byte *)in_EDX;
          if ((byte)uVar11 != (byte)puVar17[6]) goto LAB_1000_2c73;
          uVar10 = CONCAT11((char)((uint)uVar11 >> 8),(byte)uVar11 & (in_BX + (int)puVar17)[100]);
          puVar2 = puVar17 + 3;
          uVar12 = *puVar2;
          uVar5 = *puVar2;
          *puVar2 = *puVar2 + uVar10;
          uVar3 = *puVar2;
          uVar4 = *puVar2;
          if (CARRY2(uVar12,uVar10)) {
            puVar17[3] = 0xffff;
          }
          if ((int)uVar3 < 0) {
            uVar12 = uVar10;
            if (uVar4 == 0 || !SCARRY2(uVar5,uVar10)) goto code_r0x00012cb1;
            goto code_r0x00012cdf;
          }
          unaff_DI = (byte *)((uint)unaff_DI ^ (uint)pbVar15);
        }
        else {
          (in_BX + (int)unaff_DI)[-0x47] = (in_BX + (int)unaff_DI)[-0x47] + bVar14;
          iVar9 = uVar12 + *(int *)(in_BX + (int)puVar17);
          while( true ) {
            bVar13 = (byte)((uint)iVar9 >> 8);
            if (bVar13 == unaff_DI[-0x2d82]) {
              *(uint *)(in_BX + (int)puVar17) =
                   (*(int *)(in_BX + (int)puVar17) - (int)(byte *)in_EDX) -
                   (uint)(bVar13 < unaff_DI[-0x2d82]);
              in((byte *)in_EDX);
              unaff_SS = iStack_2;
            }
            iVar9 = (uint)bVar13 << 8;
            bVar19 = (byte *)0xffa5 < unaff_DI;
            unaff_DI = unaff_DI + 0x5a;
            in_CX = iStack_2 - 1;
            if (in_CX == 0) break;
            iStack_2 = 3;
          }
          uVar10 = func_0x0001a4ee();
          bVar20 = true;
          if (bVar19) goto LAB_1000_2c9b_2;
        }
LAB_1000_2c73:
        in_CX = CONCAT11((char)(in_CX >> 8),(byte)in_CX | *in_BX);
        *(byte *)(puVar16 + 6) = 4;
        puVar16[3] = 200;
        *(byte *)((int)puVar16 + 0xb) = 0xff;
        uVar11 = in(0x20);
        puVar17 = (uint *)((int)puVar16 + -1);
        in_BX[(int)puVar17] = in_BX[(int)puVar17] + (char)in_BX;
        puVar2 = (uint *)(in_BX + (int)puVar17);
        *puVar2 = *puVar2 ^ in_CX;
        if (*puVar2 == 0) {
          bVar13 = (byte)uVar11;
          uVar21 = 0x17 < bVar13;
          uVar12 = CONCAT11((char)((uint)uVar11 >> 8),bVar13 - 0x18);
          if ((byte)(bVar13 - 0x18) != '\0' && '\x17' < (char)bVar13) {
            if (!(bool)uVar21) {
              return uVar12;
            }
            cVar22 = CARRY2((uint)in_BX,uVar12);
            pbVar15 = in_BX + uVar12;
            FUN_1000_91b2(uVar23);
            bVar13 = (byte)((uint)*(undefined2 *)(byte *)((int)puVar16 + 1) >> 8);
            cVar8 = func_0x0001a45f();
            if ((bool)cVar22) {
              return (uint)(byte)(cVar8 + *(byte *)(unaff_BP + (int)puVar17) + 1);
            }
            FUN_1000_9213();
            *(byte *)(unaff_BP + (int)puVar17) =
                 (*(byte *)(unaff_BP + (int)puVar17) - extraout_AH) - cVar22;
            bVar19 = false;
            unaff_DI[unaff_BP + 0x2f] = unaff_DI[unaff_BP + 0x2f] ^ bVar13;
            uVar12 = FUN_1000_343c();
            if (!bVar19) {
              return uVar12;
            }
            uVar12 = func_0x000134ff();
            if (bVar19) {
              uVar5 = *(uint *)(pbVar15 + 0x1287);
              puVar2 = (uint *)((int)puVar17 + unaff_BP + 1);
              *puVar2 = *puVar2 | (uint)puVar17;
              return (uint)(byte)(((char)uVar12 + '\x18') - (uVar5 < 0x5c));
            }
            return uVar12;
          }
        }
        else {
          while( true ) {
            bVar19 = (byte)uVar11 < 0x14;
            bVar13 = (byte)((uint)uVar11 >> 8);
            bVar7 = -bVar19;
            uVar11 = CONCAT11(bVar13,bVar7);
            pbVar6 = (byte *)(unaff_BP + (int)puVar17);
            *pbVar6 = *pbVar6 + (char)((uint)in_BX >> 8) + bVar19;
            if (*pbVar6 == 0) break;
            *(byte *)((int)puVar16 + 0x7b) =
                 *(byte *)((int)puVar16 + 0x7b) | (byte)((ulong)in_EDX >> 8);
          }
          uVar21 = false;
          bVar19 = false;
          bVar13 = bVar13 | in_BX[(int)puVar17];
          uVar12 = CONCAT11(bVar13,bVar7);
          cVar8 = '\0';
          if (bVar13 != 0) {
            bVar13 = unaff_DI[-0x2d7e] - 8;
            bVar19 = bVar13 < 8;
            while( true ) {
              pbVar15 = (byte *)in_EDX;
              if (bVar19) {
                uVar12 = CONCAT11(bVar13,bVar7) & 0x3ff;
                bVar7 = (byte)(uVar12 >> 8);
                bVar13 = (byte)uVar12;
                uVar21 = bVar13 < bVar7;
                bVar19 = SBORROW1(bVar13,bVar7);
                cVar8 = bVar13 - bVar7;
                if (bVar13 != bVar7) goto LAB_1000_2d0a;
              }
              uVar10 = func_0x0001a4c2();
code_r0x00012cb1:
              if (-1 < (char)(in_BX + (int)unaff_DI)[-0x56]) break;
              *(byte *)puVar17 = (byte)*puVar17 | (byte)uVar10;
              in_EDX = (byte *)(ulong)CONCAT11((byte)((uint)pbVar15 >> 8) |
                                               *(byte *)((int)puVar17 + unaff_BP + 6),(char)pbVar15)
              ;
              puVar2 = puVar17;
              bVar20 = CARRY2(*puVar2,(uint)in_BX);
              *puVar2 = (uint)(in_BX + *puVar2);
LAB_1000_2c9b_2:
              in_EDX = (byte *)CONCAT31((int3)((ulong)in_EDX >> 8),(char)in_EDX + -0x80 + bVar20);
              bVar13 = (byte)(uVar10 >> 8);
              bVar7 = in((byte *)in_EDX);
              bVar19 = false;
              (in_BX + (int)puVar17)[0x8fc] = (in_BX + (int)puVar17)[0x8fc] | bVar7;
            }
            out(pbVar15,uVar10);
            unaff_DI[uVar10 + 599] = (byte)in_CX;
            cVar8 = func_0x0001b538();
            uVar18 = 0x2000;
            pbVar15 = (byte *)CONCAT11(cVar8 + '\b',in_BX[0x12]);
            puVar17 = (uint *)0x0;
            in_CX = 0x900;
            unaff_DI = (byte *)0x2;
            uVar12 = *(uint *)0xd27e;
            unaff_BP = uVar10;
code_r0x00012cdf:
            if (((char)uVar12 == (char)((uint)pbVar15 >> 8)) && (*puVar17 < 0x4000)) {
              uVar12 = ((uint)pbVar15 & 0xff) * (uVar12 >> 8);
              if ((char)(uVar12 >> 8) != '\0') {
                puVar2 = (uint *)(in_BX + 0xe);
                uVar5 = *puVar2;
                *puVar2 = *puVar2 + uVar12;
                *(uint *)(in_BX + 0x10) = *(int *)(in_BX + 0x10) + (uint)CARRY2(uVar5,uVar12);
                *(byte *)(puVar17 + -0x16c0) = (byte)puVar17[-0x16c0] - (char)uVar12;
                if (in_CX - 1 != 0) {
                  bVar13 = (byte)(in_CX - 1);
                  unaff_DI[unaff_BP + 0x7e84] = unaff_DI[unaff_BP + 0x7e84] + bVar13;
                  ((byte *)((int)puVar17 + 1) + (int)unaff_DI)[unaff_BP] =
                       (char)((byte *)((int)puVar17 + 1) + (int)unaff_DI)[unaff_BP] >>
                       (bVar13 & 0x1f);
                    /* WARNING: Bad instruction - Truncating control flow here */
                  halt_baddata();
                }
              }
            }
            return param_3._1_2_;
          }
LAB_1000_2d0a:
          if (bVar19 != cVar8 < '\0') {
            in_BX = in_BX + uVar12;
            goto code_r0x00012d12;
          }
          uVar12 = FUN_1000_a08e();
        }
        if ((bool)uVar21) {
          return uVar12;
        }
code_r0x00012d12:
        FUN_1000_38b6();
        bVar13 = *(byte *)((int)puVar17 + 0xb);
        bVar19 = bVar13 < in_BX[(int)unaff_DI] ||
                 (byte)(bVar13 - in_BX[(int)unaff_DI]) < (bVar13 != 0xff);
        uVar12 = FUN_1000_342c();
        if (bVar19) {
          return (uint)*(byte *)0x42e;
        }
        return uVar12;
      }
    }
    else {
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar8 + 1;
      unaff_DI = (byte *)0x301;
    }
    bVar13 = 1;
    if (unaff_SI <= unaff_DI) {
      unaff_DI = unaff_DI + -(int)unaff_SI;
    }
    in_CX = in_CX - 1;
    if (in_CX == 0) {
      *(undefined2 *)0x3bea = unaff_DI;
      return in_AX;
    }
    unaff_SI[unaff_BP] = (char)unaff_SI[unaff_BP] >> ((byte)in_CX & 0x1f);
  } while( true );
}


