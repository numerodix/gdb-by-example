# C primitive types


* [Characters and strings](#characters-and-strings)
  * [char](#char)
* [Unsigned integers](#unsigned-integers)
  * [unsigned char](#unsigned-char)
  * [unsigned short](#unsigned-short)
  * [unsigned int](#unsigned-int)
  * [unsigned long long](#unsigned-long-long)
* [Signed integers](#signed-integers)
  * [char](#char)
  * [short](#short)
  * [int](#int)
  * [long long](#long-long)
* [Floating point numbers](#floating-point-numbers)
  * [float](#float)


## Characters and strings


### char

- Size: 1 byte / 8 bits
- Charset: ASCII

```
char initial = 'H';
char *pinitial = &initial;
char name[] = "Hans Zimmer";
char *pname = &name[0];
```

#### char

| Format               | Command         | Output   |
|----------------------|-----------------|----------|
| show type            | `ptype initial` | `char`   |
| **print as default** | `p initial`     | `72 'H'` |
| print as number      | `p/d initial`   | `72`     |
| **examine as char**  | `x/c &initial`  | `72 'H'` |

#### char* (to a single char)

| Format                     | Command          | Output                     |
|----------------------------|------------------|----------------------------|
| show type                  | `ptype pinitial` | `char *`                   |
| print as default           | `p pinitial`     | `"H\363H\356\377\377\377"` |
| **print deref as default** | `p *pinitial`    | `72 'H'`                   |
| **examine as char**        | `x/c pinitial`   | `72 'H'`                   |

#### char[] (as a string)

| Format                | Command      | Output                        |
|-----------------------|--------------|-------------------------------|
| show type             | `ptype name` | `char [12]`                   |
| **print as default**  | `p name`     | `"Hans Zimmer"`               |
| print as number array | `p/d name`   | `{72, 97, 110, 115, 32, ...}` |
| **examine as string** | `x/s name`   | `"Hans Zimmer"`               |

#### char* (to a string)

| Format                         | Command       | Output                                |
|--------------------------------|---------------|---------------------------------------|
| show type                      | `ptype pname` | `char *`                              |
| **print as default**           | `p pname`     | `"Hans Zimmer"`                       |
| print deref as default         | `p *pname`    | `72 'H'`                              |
| print deref as string          | `p/s *pname`  | `72 'H'`                              |
| examine as char                | `x/c pname`   | `72 'H'`                              |
| **examine as chars with size** | `x/12c name`  | `72 'H'  97 'a'  110 'n' 115 's' ...` |
| **examine as string**          | `x/s pname`   | `"Hans Zimmer"`                       |



## Unsigned integers



### unsigned char

- Size: 1 byte / 8 bits
- Min: 0
- Max: 255

```
// village population: 243
unsigned char village = 243;
unsigned char *pvillage = &village;
unsigned char villages[] = {243, 113, 54};
unsigned char *pvillages = &villages[0];
```

#### unsigned char

| Format                | Command         | Output          |
|-----------------------|-----------------|-----------------|
| show type             | `ptype village` | `unsigned char` |
| print as default      | `p village`     | `243 '\363'`    |
| **print as unsigned** | `p/u village`   | `243`           |
| print as signed       | `p/d village`   | `-13`           |
| display as binary     | `p/t village`   | `11110011`      |
| display as hex        | `p/x village`   | `0xf3`          |

#### unsigned char* (to a single char)

| Format                          | Command          | Output                         |
|---------------------------------|------------------|--------------------------------|
| show type                       | `ptype pvillage` | `unsigned char *`              |
| print as default                | `p pvillage`     | `0x7fffffffdfef "\363\356..."` |
| print deref as default          | `p *pvillage`    | `243 '\363'`                   |
| **print deref as unsigned**     | `p/u *pvillage`  | `243`                          |
| print deref as signed           | `p/d *pvillage`  | `-13`                          |
| examine as default              | `x pvillage`     | `0x7fffffffdfef: 11110011`     |
| **examine as single char/byte** | `x/1ub pvillage` | `243`                          |

#### unsigned char[]

| Format                     | Command          | Output                         |
|----------------------------|------------------|--------------------------------|
| show type                  | `ptype villages` | `unsigned char [3]`            |
| print as default           | `p villages`     | `"\363q6"`                     |
| **print as unsigned**      | `p/u villages`   | `{243, 113, 54}`               |
| print as signed            | `p/d villages`   | `{-13, 113, 54}`               |
| examine as default         | `x villages`     | `0x7fffffffe019: 11110011`     |
| **examine as three chars** | `x/3ub villages` | `243     113     54`           |
| examine ... in binary      | `x/3tb villages` | `11110011  01110001  00110110` |
| examine ... in hex         | `x/3xb villages` | `0xf3  0x71  0x36`             |

#### unsigned char* (to an array)

| Format                     | Command           | Output                       |
|----------------------------|-------------------|------------------------------|
| show type                  | `ptype pvillages` | `unsigned char *`            |
| print as default           | `p pvillages`     | `0x7fffffffe019 "\363q6..."` |
| print deref as unsigned    | `p/u *pvillages`  | `243`                        |
| print deref as signed      | `p/d *pvillages`  | `-13`                        |
| examine as default         | `x pvillages`     | `0x7fffffffe019: -13`        |
| **examine as three chars** | `x/3ub pvillages` | `243     113     54`         |



### unsigned short

- Size: 2 bytes / 16 bits
- Min: 0
- Max: 65,535

```
// town population: 61,000
unsigned short town = 61000;
unsigned short *ptown = &town;
unsigned short towns[] = {61000, 33109, 41001};
unsigned short *ptowns = &towns[0];
```

#### unsigned short

| Format                | Command      | Output             |
|-----------------------|--------------|--------------------|
| show type             | `ptype town` | `unsigned short`   |
| **print as default**  | `p town`     | `61000`            |
| **print as unsigned** | `p/u town`   | `61000`            |
| print as signed       | `p/d town`   | `-4536`            |
| display as binary     | `p/t town`   | `1110111001001000` |
| display as hex        | `p/x town`   | `0xee48`           |

#### unsigned short* (to a single short)

| Format                      | Command       | Output                       |
|-----------------------------|---------------|------------------------------|
| show type                   | `ptype ptown` | `unsigned short *`           |
| print as default            | `p ptown`     | `0x7fffffffdfd6`             |
| **print deref as default**  | `p *ptown`    | `61000`                      |
| **print deref as unsigned** | `p/u *ptown`  | `61000`                      |
| print deref as signed       | `p/d *ptown`  | `-4536`                      |
| examine as default          | `x ptown`     | `0x7fffffffdfd6: -539693496` |
| **examine as single short** | `x/1uh ptown` | `61000`                      |

#### unsigned short[]

| Format                      | Command       | Output                    |
|-----------------------------|---------------|---------------------------|
| show type                   | `ptype towns` | `unsigned short [3]`      |
| **print as default**        | `p towns`     | `{61000, 33109, 41001}`   |
| **print as unsigned**       | `p/u towns`   | `{61000, 33109, 41001}`   |
| print as signed             | `p/d towns`   | `{-4536, -32427, -24535}` |
| examine as default          | `x towns`     | `0x7fffffffe012: -4536`   |
| **examine as three shorts** | `x/3uh towns` | `61000   33109   41001`   |
| examine ... in binary       | `x/3th towns` | `1110111001001000 ...`    |
| examine ... in hex          | `x/3xh towns` | `0xee48  0x8155  0xa029`  |

#### unsigned short* (to an array)

| Format                      | Command        | Output                  |
|-----------------------------|----------------|-------------------------|
| show type                   | `ptype ptowns` | `unsigned char *`       |
| print as default            | `p ptowns`     | `0x7fffffffe012`        |
| print deref as unsigned     | `p/u *ptowns`  | `61000`                 |
| print deref as signed       | `p/d *ptowns`  | `-4536`                 |
| examine as default          | `x ptowns`     | `-4536`                 |
| **examine as three shorts** | `x/3uh ptowns` | `61000   33109   41001` |



### unsigned int

- Size: 4 bytes / 32 bits
- Min: 0
- Max: 4,294,967,295

```
// planet population: 4,043,309,055
unsigned int planet = 4043309055;
unsigned int *pplanet = &planet;
unsigned int planets[] = {planet, planet / 2, planet / 6};
unsigned int *pplanets = &planets[0];
```

#### unsigned int

| Format                | Command        | Output           |
|-----------------------|----------------|------------------|
| show type             | `ptype planet` | `unsigned int`   |
| **print as default**  | `p planet`     | `4043309055`     |
| **print as unsigned** | `p/u planet`   | `4043309055`     |
| print as signed       | `p/d planet`   | `-251658241`     |
| display as binary     | `p/t planet`   | `11110000111...` |
| display as hex        | `p/x planet`   | `0xf0ffffff`     |

#### unsigned int* (to a single int)

| Format                      | Command         | Output                       |
|-----------------------------|-----------------|------------------------------|
| show type                   | `ptype pplanet` | `unsigned int *`             |
| print as default            | `p pplanet`     | `0x7fffffffdfb4`             |
| **print deref as default**  | `p *pplanet`    | `4043309055`                 |
| **print deref as unsigned** | `p/u *pplanet`  | `4043309055`                 |
| print deref as signed       | `p/d *pplanet`  | `-251658241`                 |
| examine as default          | `x pplanet`     | `0x7fffffffdfb4: -251658241` |
| **examine as single int**   | `x/1uw pplanet` | `4043309055`                 |

#### unsigned int[]

| Format                    | Command         | Output                          |
|---------------------------|-----------------|---------------------------------|
| show type                 | `ptype planets` | `unsigned int [3]`              |
| **print as default**      | `p planets`     | `{4043309055, 2021654527, ...}` |
| **print as unsigned**     | `p/u planets`   | `{4043309055, 2021654527, ...}` |
| print as signed           | `p/d planets`   | `{-251658241, 2021654527, ...}` |
| examine as default        | `x planets`     | `0x7fffffffe00c: -251658241`    |
| **examine as three ints** | `x/3uw planets` | `4043309055   2021654527  ...`  |
| examine ... in binary     | `x/3tw planets` | `11110000111... ...`            |
| examine ... in hex        | `x/3xw planets` | `0xf0ffffff   0x787fffff  ...`  |

#### unsigned int* (to an array)

| Format                    | Command          | Output                          |
|---------------------------|------------------|---------------------------------|
| show type                 | `ptype pplanets` | `unsigned int *`                |
| print as default          | `p pplanets`     | `0x7fffffffe00c`                |
| print deref as unsigned   | `p/u *pplanets`  | `4043309055`                    |
| print deref as signed     | `p/d *pplanets`  | `-251658241`                    |
| examine as default        | `x pplanets`     | `4043309055`                    |
| **examine as three ints** | `x/3uw pplanets` | `4043309055   2021654527   ...` |



### unsigned long long

- Size: 8 bytes / 64 bits
- Min: 0
- Max: 18,446,744,073,709,551,615

```
// universe population: 10,376,293,541,461,622,784
unsigned long long universe = 10376293541461622784LLU;
unsigned long long *puniverse = &universe;
unsigned long long universes[] = {universe, universe / 2, universe / 6};
unsigned long long *puniverses = &universes[0];
```

#### unsigned long long

| Format                | Command          | Output                   |
|-----------------------|------------------|--------------------------|
| show type             | `ptype universe` | `unsigned long long`     |
| **print as default**  | `p universe`     | `10376293541461622784`   |
| **print as unsigned** | `p/u universe`   | `10376293541461622784`   |
| print as signed       | `p/d universe`   | `-8070450532247928832`   |
| display as binary     | `p/t universe`   | `1001000000000000000...` |
| display as hex        | `p/x universe`   | `0x9000000000000000`     |

#### unsigned long long* (to a single long long)

| Format                          | Command           | Output                       |
|---------------------------------|-------------------|------------------------------|
| show type                       | `ptype puniverse` | `unsigned long long *`       |
| print as default                | `p puniverse`     | `0x7fffffffdf88`             |
| **print deref as default**      | `p *puniverse`    | `10376293541461622784`       |
| **print deref as unsigned**     | `p/u *puniverse`  | `10376293541461622784`       |
| print deref as signed           | `p/d *puniverse`  | `-8070450532247928832`       |
| examine as default              | `x puniverse`     | `0x7fffffffdf88: 10376...`
| **examine as single long long** | `x/1ug puniverse` | `10376293541461622784`       |

#### unsigned long long[]

| Format                          | Command           | Output                         |
|---------------------------------|-------------------|--------------------------------|
| show type                       | `ptype universes` | `unsigned long long [3]`       |
| **print as default**            | `p universes`     | `{10376293541461622784, ...}`  |
| **print as unsigned**           | `p/u universes`   | `{10376293541461622784, ...}`  |
| print as signed                 | `p/d universes`   | `{-8070450532247928832, ...}`  |
| examine as default              | `x universes`     | `0x7fffffffe000: 1037629...`   |
| **examine as three long longs** | `x/3ug universes` | `10376293541461622784 ... ...` |
| examine ... in binary           | `x/3tg universes` | `100100000000... ...`          |
| examine ... in hex              | `x/3xg universes` | `0x9000000000000000 ...`       |

#### unsigned long long* (to an array)

| Format                          | Command            | Output                     |
|---------------------------------|--------------------|----------------------------|
| show type                       | `ptype puniverses` | `unsigned long long *`     |
| print as default                | `p puniverses`     | `0x7fffffffe000`           |
| print deref as unsigned         | `p/u *puniverses`  | `10376293541461622784`     |
| print deref as signed           | `p/d *puniverses`  | `-8070450532247928832`     |
| examine as default              | `x puniverses`     | `10376293541461622784`     |
| **examine as three long longs** | `x/3ug puniverses` | `10376293541461622784 ...` |




## Signed integers



### char

- Size: 1 byte / 8 bits
- Min: -128
- Max: 127

```
// a planet's surface temperature: -121 C
char surface = -121;
char *psurface = &surface;
char surfaces[] = {-121, -97, -56};
char *psurfaces = &surfaces[0];
```

#### char

| Format              | Command         | Output        |
|---------------------|-----------------|---------------|
| show type           | `ptype surface` | `char`        |
| print as default    | `p surface`     | `-121 '\207'` |
| print as unsigned   | `p/u surface`   | `135`         |
| **print as signed** | `p/d surface`   | `-121`        |
| display as binary   | `p/t surface`   | `10000111`    |
| display as hex      | `p/x surface`   | `0x87`        |

#### char* (to a single char)

| Format                          | Command          | Output                       |
|---------------------------------|------------------|------------------------------|
| show type                       | `ptype psurface` | `char *`                     |
| print as default                | `p psurface`     | `"\207H\356\364\204...`      |
| print deref as default          | `p *psurface`    | `-121 '\207'`                |
| print deref as unsigned         | `p/u *psurface`  | `135`                        |
| **print deref as signed**       | `p/d *psurface`  | `-121`                       |
| examine as default              | `x psurface`     | `0x7fffffffdf0b: -185710457` |
| **examine as single char/byte** | `x/1db psurface` | `-121`                       |

#### char[]

| Format                     | Command          | Output                           |
|----------------------------|------------------|----------------------------------|
| show type                  | `ptype surfaces` | `char [3]`                       |
| print as default           | `p surfaces`     | `"\207\237...`                   |
| print as unsigned          | `p/u surfaces`   | `{135, 159, 200}`                |
| **print as signed**        | `p/d surfaces`   | `{-121, -97, -56}`               |
| examine as default         | `x surfaces`     | `0x7fffffffe029: -121`           |
| **examine as three chars** | `x/3db surfaces` | `-121  -97  -56`                 |
| examine ... in binary      | `x/3tb surfaces` | `10000111   10011111   11001000` |
| examine ... in hex         | `x/3xb surfaces` | `0x87  0x9f  0xc8`               |

#### char* (to an array)

| Format                     | Command           | Output                        |
|----------------------------|-------------------|-------------------------------|
| show type                  | `ptype psurfaces` | `char *`                      |
| print as default           | `p psurfaces`     | `0x7fffffffe029 "\207\237...` |
| print deref as unsigned    | `p/u *psurfaces`  | `135`                         |
| print deref as signed      | `p/d *psurfaces`  | `-121`                        |
| examine as default         | `x psurfaces`     | `0x7fffffffe029: -121`        |
| **examine as three chars** | `x/3db psurfaces` | `-121   -97   -56`            |



### short

- Size: 2 bytes / 16 bits
- Min: -32,768
- Max: 32,767

```
// credit card debt: 31,500 
short balance = -31500;
short *pbalance = &balance;
short balances[] = {-31500, -29130, -15120};
short *pbalances = &balances[0];
```

#### short

| Format               | Command         | Output             |
|----------------------|-----------------|--------------------|
| show type            | `ptype balance` | `short`            |
| **print as default** | `p balance`     | `-31500`           |
| print as unsigned    | `p/u balance`   | `34036`            |
| **print as signed**  | `p/d balance`   | `-31500`           |
| display as binary    | `p/t balance`   | `1000010011110100` |
| display as hex       | `p/x balance`   | `0x84f4`           |

#### short* (to a single short)

| Format                      | Command          | Output                |
|-----------------------------|------------------|-----------------------|
| show type                   | `ptype pbalance` | `short *`             |
| print as default            | `p pbalance`     | `0x7fffffffdf0e`      |
| **print deref as default**  | `p *pbalance`    | `-31500`              |
| print deref as unsigned     | `p/u *pbalance`  | `34036`               |
| **print deref as signed**   | `p/d *pbalance`  | `-31500`              |
| examine as default          | `x pbalance`     | `0x7fffffffdf0e: -12` |
| **examine as single short** | `x/1dh pbalance` | `-31500`              |

#### short[]

| Format                      | Command          | Output                     |
|-----------------------------|------------------|----------------------------|
| show type                   | `ptype balances` | `short [3]`                |
| **print as default**        | `p balances`     | `{-31500, -29130, -15120}` |
| print as unsigned           | `p/u balances`   | `{34036, 36406, 50416}`    |
| **print as signed**         | `p/d balances`   | `{-31500, -29130, -15120}` |
| examine as default          | `x balances`     | `0x7fffffffdfc2: -31500`   |
| **examine as three shorts** | `x/3uh balances` | `-31500   -29130   -15120` |
| examine ... in binary       | `x/3th balances` | `1000010011110100 ...`     |
| examine ... in hex          | `x/3xh balances` | `0x84f4  0x8e36  0xc4f0`   |

#### short* (to an array)

| Format                      | Command           | Output                     |
|-----------------------------|-------------------|----------------------------|
| show type                   | `ptype pbalances` | `short *`                  |
| print as default            | `p pbalances`     | `0x7fffffffdfc2`           |
| print deref as unsigned     | `p/u *pbalances`  | `34036`                    |
| print deref as signed       | `p/d *pbalances`  | `-31500`                   |
| examine as default          | `x pbalances`     | `-31500`                   |
| **examine as three shorts** | `x/3xh pbalances` | `-31500   -29130   -15120` |



### int

- Size: 4 bytes / 32 bits
- Min: -2,147,483,648
- Max: 2,147,483,647

```
// VC funded company earnings: -2,120,401,005
int profit = -2120401005;
int *pprofit = &profit;
int profits[] = {profit, profit / 2, profit / 6};
int *pprofits = &profits[0];
```

#### int

| Format               | Command        | Output          |
|----------------------|----------------|-----------------|
| show type            | `ptype profit` | `int`           |
| **print as default** | `p profit`     | `-2120401005`   |
| print as unsigned    | `p/u profit`   | `2174566291`    |
| **print as signed**  | `p/d profit`   | `-2120401005`   |
| display as binary    | `p/t profit`   | `1000000110...` |
| display as hex       | `p/x profit`   | `0x819d3f93`    |

#### int* (to a single int)

| Format                     | Command         | Output                         |
|----------------------------|-----------------|--------------------------------|
| show type                  | `ptype pprofit` | `int *`                        |
| print as default           | `p pprofit`     | `0x7fffffffdf14`               |
| **print deref as default** | `p *pprofit`    | `-2120401005`                  |
| print deref as unsigned    | `p/u *pprofit`  | `2174566291`                   |
| **print deref as signed**  | `p/d *pprofit`  | `-2120401005`                  |
| **examine as default**     | `x pprofit`     | `0x7fffffffdf14: -2120401005 ` |
| **examine as single int**  | `x/1dw pprofit` | `0x7fffffffdf14: -2120401005`  |

#### int[]

| Format                    | Command         | Output                            |
|---------------------------|-----------------|-----------------------------------|
| show type                 | `ptype profits` | `int [3]`                         |
| **print as default**      | `p profits`     | `{-2120401005, -1060200502, ...}` |
| print as unsigned         | `p/u profits`   | `{2174566291, 3234766794, ...}`   |
| **print as signed**       | `p/d profits`   | `{-2120401005, -1060200502, ...}` |
| examine as default        | `x profits`     | `0x7fffffffdfd4: -2120401005 `    |
| **examine as three ints** | `x/3dw profits` | `-2120401005   -1060200502 ...`   |
| examine ... in binary     | `x/3tw profits` | `1000000110... ...`               |
| examine ... in hex        | `x/3xw profits` | `0x819d3f93   0xc0ce9fca   ...`   |

#### int* (to an array)

| Format                    | Command          | Output                            |
|---------------------------|------------------|-----------------------------------|
| show type                 | `ptype pprofits` | `int *`                           |
| print as default          | `p pprofits`     | `0x7fffffffdfd4`                  |
| print deref as unsigned   | `p/u *pprofits`  | `2174566291`                      |
| print deref as signed     | `p/d *pprofits`  | `-2120401005`                     |
| examine as default        | `x pprofits`     | `-2120401005`                     |
| **examine as three ints** | `x/3dw pprofits` | `-2120401005   -1060200502   ...` |



### long long

- Size: 8 bytes / 64 bits
- Min: -9,223,372,036,854,775,808
- Max: 9,223,372,036,854,775,807

```
// future world economy deficit: 8,220,802,194,093,872,013
long long deficit = -8220802194093872013LL;
long long *pdeficit = &deficit;
long long deficits[] = {deficit, deficit / 2, deficit / 6};
long long *pdeficits = &deficits[0];
```

#### long long

| Format               | Command         | Output                 |
|----------------------|-----------------|------------------------|
| show type            | `ptype deficit` | `long long`            |
| **print as default** | `p deficit`     | `-8220802194093872013` |
| print as unsigned    | `p/u deficit`   | `10225941879615679603` |
| **print as signed**  | `p/d deficit`   | `-8220802194093872013` |
| display as binary    | `p/t deficit`   | `1000110111...`        |
| display as hex       | `p/x deficit`   | `0x8de9d7f5cc486c73`   |

#### long long* (to a single long long)

| Format                          | Command          | Output                         |
|---------------------------------|------------------|--------------------------------|
| show type                       | `ptype pdeficit` | `long long *`                  |
| print as default                | `p pdeficit`     | `0x7fffffffdf30`               |
| **print deref as default**      | `p *pdeficit`    | `-8220802194093872013`         |
| print deref as unsigned         | `p/u *pdeficit`  | `10225941879615679603`         |
| **print deref as signed**       | `p/d *pdeficit`  | `-8220802194093872013`         |
| examine as default              | `x pdeficit`     | `0x7fffffffdf88: -82208021...` |
| **examine as single long long** | `x/1dg pdeficit` | `-8220802194093872013`         |

#### long long[]

| Format                          | Command          | Output                        |
|---------------------------------|------------------|-------------------------------|
| show type                       | `ptype deficits` | `long long [3]`               |
| **print as default**            | `p deficits`     | `{-8220802194093872013, ...}` |
| print as unsigned               | `p/u deficits`   | `{10225941879615679603, ...}` |
| **print as signed**             | `p/d deficits`   | `{-8220802194093872013, ...}` |
| examine as default              | `x deficits`     | `0x7fffffffe000: -822080...`  |
| **examine as three long longs** | `x/3dg deficits` | `-8220802194093872013 ...`    |
| examine ... in binary           | `x/3tg deficits` | `100011011... ...`            |
| examine ... in hex              | `x/3xg deficits` | `0x8de9d7f5cc486c73 ...`      |

#### long long* (to an array)

| Format                          | Command           | Output                     |
|---------------------------------|-------------------|----------------------------|
| show type                       | `ptype pdeficits` | `long long *`              |
| print as default                | `p pdeficits`     | `0x7fffffffe010`           |
| print deref as unsigned         | `p/u *pdeficits`  | `10225941879615679603`     |
| print deref as signed           | `p/d *pdeficits`  | `-8220802194093872013`     |
| examine as default              | `x pdeficits`     | `-8220802194093872013`     |
| **examine as three long longs** | `x/3dg pdeficits` | `-8220802194093872013 ...` |



## Floating point numbers



### float

- Size: 4 bytes / 32 bits
- Min: -3.4e-38
- Max: 3.4e38

```
// mass of photon: 8.56e-38
float photon = 8.56e-38;
float *pphoton = &photon;
// add electron and proton
float particles[] = {photon, 9.10e-31, 1.67e-27};
float *pparticles = &particles[0];
```

#### unsigned char

| Format                | Command         | Output          |
|-----------------------|-----------------|-----------------|
| show type             | `ptype village` | `unsigned char` |
| print as default      | `p village`     | `243 '\363'`    |
| **print as unsigned** | `p/u village`   | `243`           |
| print as signed       | `p/d village`   | `-13`           |
| display as binary     | `p/t village`   | `11110011`      |
| display as hex        | `p/x village`   | `0xf3`          |

#### unsigned char* (to a single char)

| Format                          | Command          | Output                         |
|---------------------------------|------------------|--------------------------------|
| show type                       | `ptype pvillage` | `unsigned char *`              |
| print as default                | `p pvillage`     | `0x7fffffffdfef "\363\356..."` |
| print deref as default          | `p *pvillage`    | `243 '\363'`                   |
| **print deref as unsigned**     | `p/u *pvillage`  | `243`                          |
| print deref as signed           | `p/d *pvillage`  | `-13`                          |
| examine as default              | `x pvillage`     | `0x7fffffffdfef: 11110011`     |
| **examine as single char/byte** | `x/1ub pvillage` | `243`                          |

#### unsigned char[]

| Format                     | Command          | Output                         |
|----------------------------|------------------|--------------------------------|
| show type                  | `ptype villages` | `unsigned char [3]`            |
| print as default           | `p villages`     | `"\363q6"`                     |
| **print as unsigned**      | `p/u villages`   | `{243, 113, 54}`               |
| print as signed            | `p/d villages`   | `{-13, 113, 54}`               |
| examine as default         | `x villages`     | `0x7fffffffe019: 11110011`     |
| **examine as three chars** | `x/3ub villages` | `243     113     54`           |
| examine ... in binary      | `x/3tb villages` | `11110011  01110001  00110110` |
| examine ... in hex         | `x/3xb villages` | `0xf3  0x71  0x36`             |

#### unsigned char* (to an array)

| Format                     | Command           | Output                       |
|----------------------------|-------------------|------------------------------|
| show type                  | `ptype pvillages` | `unsigned char *`            |
| print as default           | `p pvillages`     | `0x7fffffffe019 "\363q6..."` |
| print deref as unsigned    | `p/u *pvillages`  | `243`                        |
| print deref as signed      | `p/d *pvillages`  | `-13`                        |
| examine as default         | `x pvillages`     | `0x7fffffffe019: -13`        |
| **examine as three chars** | `x/3ub pvillages` | `243     113     54`         |
