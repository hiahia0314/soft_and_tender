//
// Created by 23125 on 2023/12/26.
//
#include "common.h"


int SDL_main(int argc,char *argv[]){
    srand((unsigned)time(NULL));
    ran = rand()%50;
    IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG);
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
    TTF_Init();
    Mix_Init(MIX_INIT_MP3);

    Window = SDL_CreateWindow("run",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,700,900,SDL_WINDOW_SHOWN);
    Renderer= SDL_CreateRenderer(Window,-1,SDL_RENDERER_ACCELERATED);

    LOAD();
    SDL_RenderClear(Renderer);//产生图片
    SDL_RenderCopy(Renderer,MainBackGroundTexture,NULL,NULL);
    SDL_RenderPresent(Renderer);//刷新

    GameOverSurface= TTF_RenderUTF8_Blended(GameOverFont,"*start*",Life_Z_Color);
    GameOverTexture= SDL_CreateTextureFromSurface(Renderer,GameOverSurface);
    GameOverRect.x=135;
    GameOverRect.y=671;
    GameOverRect.h=GameOverSurface->h;
    GameOverRect.w=GameOverSurface->w;
    SDL_RenderCopy(Renderer,GameOverTexture,NULL,&GameOverRect);
    SDL_RenderPresent(Renderer);

    GameOverSurface= TTF_RenderUTF8_Blended(GameOverFont,"*start*",Life_Z_Color);
    GameOverTexture= SDL_CreateTextureFromSurface(Renderer,GameOverSurface);
    GameOverRect.x=135;
    GameOverRect.y=673;
    GameOverRect.h=GameOverSurface->h;
    GameOverRect.w=GameOverSurface->w;
    SDL_RenderCopy(Renderer,GameOverTexture,NULL,&GameOverRect);
    SDL_RenderPresent(Renderer);

    GameOverSurface= TTF_RenderUTF8_Blended(GameOverFont,"*start*",Life_Z_Color);
    GameOverTexture= SDL_CreateTextureFromSurface(Renderer,GameOverSurface);
    GameOverRect.x=135;
    GameOverRect.y=675;
    GameOverRect.h=GameOverSurface->h;
    GameOverRect.w=GameOverSurface->w;
    SDL_RenderCopy(Renderer,GameOverTexture,NULL,&GameOverRect);
    SDL_RenderPresent(Renderer);

    SDL_Event MainEvent;
    while (SDL_WaitEvent(&MainEvent)){
        switch (MainEvent.type) {//键盘交互
            case SDL_QUIT:
                QUIT();
                break;
            case SDL_KEYDOWN:
                switch (MainEvent.key.keysym.sym) {
                    case SDLK_RETURN:
                        PLAY();
                        break;
                    case SDLK_ESCAPE:
                        QUIT();
                        break;
                    default:
                        break;
                }
                break;
            case SDL_MOUSEBUTTONUP:                           //597...为start的地方
                if (MainEvent.button.x>205&&MainEvent.button.x<597&&MainEvent.button.y>651&&MainEvent.button.x<774){
                    PLAY();
                }
                break;
            default:
                break;
        }
    }
    QUIT();
}
void StandHum(){
    HumRect.x= Random(3);
    HumRect.y=-10;
    HumRect.h=SubjectHW;
    HumRect.w=SubjectHW;

    Barrier_7_Rect.x= Random(3);
    Barrier_7_Rect.y=-70;
    Barrier_7_Rect.h=SubjectHW;
    Barrier_7_Rect.w=SubjectHW;

    Barrier_12_Rect.x= Random(3);
    Barrier_12_Rect.y=-120;
    Barrier_12_Rect.h=SubjectHW;
    Barrier_12_Rect.w=SubjectHW;
//---------------------------------------------
    Bonus_1_Rect.x= Random(3);
    Bonus_1_Rect.y=-80;
    Bonus_1_Rect.h=SubjectHW;
    Bonus_1_Rect.w=SubjectHW;

    Bonus_2_Rect.x= Random(4);
    Bonus_2_Rect.y=-90;
    Bonus_2_Rect.h=SubjectHW;
    Bonus_2_Rect.w=SubjectHW;

    Bonus_3_Rect.x= Random(6);
    Bonus_3_Rect.y=-170;
    Bonus_3_Rect.h=SubjectHW;
    Bonus_3_Rect.w=SubjectHW;
//-----------------------------------------------------------
    int quit = 0;
    while (!quit) {
//加速装置 *********************
        if(DureTime>=60000){
            SPEED=17;
        }else if(DureTime>=50000){
            SPEED=14;
        }else if(DureTime>=40000){
            SPEED=12;
        } else if (DureTime>=30000){
            SPEED=10;
        } else if(DureTime>=20000){
            SPEED=8;
        } else if(DureTime>=10000){
            SPEED=7;
        } else {
            SPEED=6;
        }
//****************************
        SDL_RenderCopy(Renderer,PlayBackGroundTexture,NULL,NULL);

        if(IsDown==0&&IsFly==0&&IsHero==0){
            SDL_RenderCopy(Renderer,ManTexture,NULL,&ManRect);
        }
        if(IsHero==1){
            HeroRect.x=ManRect.x;
            HeroRect.y=ManRect.y;
            HeroRect.w=ManRect.w;
            HeroRect.h=ManRect.h;
            SDL_RenderCopy(Renderer,HeroTexture,NULL,&HeroRect);
        } else{
            if((DureFly<=DureDown||DureDown==0)&&IsFly==1){
                FlyRect.x=ManRect.x;
                FlyRect.y=ManRect.y;
                FlyRect.w=ManRect.w;
                FlyRect.h=ManRect.h;
                SDL_RenderCopy(Renderer,FlyTexture,NULL,&FlyRect);
            }
            if((DureFly==0||DureFly>=DureDown)&&IsDown==1){
                DownRect.x=ManRect.x;
                DownRect.y=ManRect.y;
                DownRect.w=ManRect.w;
                DownRect.h=ManRect.h;
                SDL_RenderCopy(Renderer,DownTexture,NULL,&DownRect);
            }
        }
//hero time
        if(IsHero==1){
            DureHero= SDL_GetTicks()-StartHero;
        }
        if(DureHero>=1700){
            IsHero=0;
        }
//  * * *** * *  flying * * ** *  *
        if(IsFly==1){
            DureFly= SDL_GetTicks() - StartFly;
        }
        if(DureFly >= 1500){
            IsFly=0;
        }
// * ** ** * * * * *down * * * *** * *
        if(IsDown==1){
            DureDown=SDL_GetTicks()-StartDown;
        }
        if(DureDown>=1500){
            IsDown=0;
        }
        //barrier
        StandBarrier();
//***********  hum
        HumRect.y += SPEED;
        SDL_RenderCopy(Renderer, HumTexture, NULL, &HumRect);
// hero
        Barrier_7_Rect.y += SPEED;
        SDL_RenderCopy(Renderer, Barrier_7_Texture, NULL, &Barrier_7_Rect);

        Barrier_12_Rect.y += SPEED;
        SDL_RenderCopy(Renderer, Barrier_12_Texture, NULL, &Barrier_12_Rect);
//bonus
        if(DureTime>=5200){
            Bonus_1_Rect.y+=SPEED;
            SDL_RenderCopy(Renderer,Bonus_1_Texture,NULL,&Bonus_1_Rect);
        }
        if(DureTime>=8200){
            Bonus_2_Rect.y+=SPEED;
            SDL_RenderCopy(Renderer,Bonus_2_Texture,NULL,&Bonus_2_Rect);
        }
        if(DureTime>=19200){
            Bonus_3_Rect.y+=SPEED;
            SDL_RenderCopy(Renderer,Bonus_3_Texture,NULL,&Bonus_3_Rect);
        }
        //eat hum
        if(ManRect.y+ManHW>=HumRect.y&&HumRect.x>ManRect.x&&HumRect.x<ManRect.x+20&&HumRect.y+SubjectHW>=ManRect.y){
            Mix_PlayChannel(-1,SoundGood,0);
            Life++;
            HumRect.y-=1000;
            HumRect.x= Random(15);
        } else if(HumRect.y>900){
            HumRect.y-=1000;
            HumRect.x= Random(10);
        }
        //
        if(ManRect.y+ManHW>=Bonus_1_Rect.y&&Bonus_1_Rect.x>ManRect.x&&Bonus_1_Rect.x<ManRect.x+20&&Bonus_1_Rect.y+SubjectHW>=ManRect.y){
            Mix_PlayChannel(-1,SoundGood,0);
            score+=200;
            Bonus_1_Rect.y-=1000;
            Bonus_1_Rect.x= Random(6);
        } else if(Bonus_1_Rect.y>900){
            Bonus_1_Rect.y-=1100;
            Bonus_1_Rect.x= Random(3);
        }
        if(ManRect.y+ManHW>=Bonus_2_Rect.y&&Bonus_2_Rect.x>ManRect.x&&Bonus_2_Rect.x<ManRect.x+20&&Bonus_2_Rect.y+SubjectHW>=ManRect.y){
            Mix_PlayChannel(-1,SoundGood,0);
            score+=200;
            Bonus_2_Rect.y-=1100;
            Bonus_2_Rect.x= Random(5);
        } else if(Bonus_2_Rect.y>900){
            Bonus_2_Rect.y-=1100;
            Bonus_2_Rect.x= Random(3);
        }
        if(ManRect.y+ManHW>=Bonus_3_Rect.y&&Bonus_3_Rect.x>ManRect.x&&Bonus_3_Rect.x<ManRect.x+20&&Bonus_3_Rect.y+SubjectHW>=ManRect.y){
            Mix_PlayChannel(-1,SoundGood,0);
            score+=200;
            Bonus_3_Rect.y-=1200;
            Bonus_3_Rect.x= Random(7);
        } else if(Bonus_3_Rect.y>900){
            Bonus_3_Rect.y-=1100;
            Bonus_3_Rect.x= Random(3);
        }

        if(((Barrier_12_Rect.x>=ManRect.x&&Barrier_12_Rect.x<=ManRect.x+50&&Barrier_12_Rect.y+SubjectHW>=ManRect.y&&Barrier_12_Rect.y<=ManRect.y+ManHW))
           &&IsHero==0){
            Mix_PlayChannel(-1,SoundBad,0);
            score-=1500;
            IsHero=1;
            Barrier_12_Rect.y-=1200;
            Barrier_12_Rect.x= Random(3);
            StartHero=SDL_GetTicks();
        } else if(Barrier_12_Rect.y>900){
            Barrier_12_Rect.y-=1200;
            Barrier_12_Rect.x= Random(3);
        }
// be hero
        if(ManRect.y+ManHW>=Barrier_7_Rect.y&&Barrier_7_Rect.x>ManRect.x&&Barrier_7_Rect.x<ManRect.x+20&&Barrier_7_Rect.y+SubjectHW>=ManRect.y){
            Mix_PlayChannel(-1,SoundGood,0);
            IsHero=1;
            StartHero=SDL_GetTicks();
            Barrier_7_Rect.y-=1200;
            Barrier_7_Rect.x= Random(9);
        } else if(Barrier_7_Rect.y>900){
            Barrier_7_Rect.y-=1100;
            Barrier_7_Rect.x= Random(9);
        }
// 撞击
        if(((BarrierRect.x>=ManRect.x&&BarrierRect.x<=ManRect.x+50&&BarrierRect.y+SubjectHW>=ManRect.y&&BarrierRect.y<=ManRect.y+ManHW)
            ||(Barrier_1_Rect.x>=ManRect.x &&Barrier_1_Rect.x<=ManRect.x+50 &&Barrier_1_Rect.y+SubjectHW>=ManRect.y &&Barrier_1_Rect.y<=ManRect.y+ManHW)
            ||(Barrier_2_Rect.x>=ManRect.x &&Barrier_2_Rect.x<=ManRect.x+50 &&Barrier_2_Rect.y+SubjectHW>=ManRect.y &&Barrier_2_Rect.y<=ManRect.y+ManHW))
           && IsHero == 0){
            Mix_PlayChannel(-1,SoundBad,0);
            score-=300;
            Life--;
            IsHero=1;
            StartHero=SDL_GetTicks();
        }

        if(((Barrier_6_Rect.x>=ManRect.x&&Barrier_6_Rect.x<=ManRect.x+50&&Barrier_6_Rect.y+SubjectHW>=ManRect.y&&Barrier_6_Rect.y<=ManRect.y+ManHW)
            ||(Barrier_4_Rect.x>=ManRect.x&&Barrier_4_Rect.x<=ManRect.x+50&&Barrier_4_Rect.y+SubjectHW>=ManRect.y&&Barrier_4_Rect.y<=ManRect.y+ManHW)
            ||(Barrier_9_Rect.x>=ManRect.x&&Barrier_9_Rect.x<=ManRect.x+50&&Barrier_9_Rect.y+SubjectHW>=ManRect.y&&Barrier_9_Rect.y<=ManRect.y+ManHW)
            ||(Barrier_11_Rect.x>=ManRect.x&&Barrier_11_Rect.x<=ManRect.x+50&&Barrier_11_Rect.y+SubjectHW>=ManRect.y&&Barrier_11_Rect.y<=ManRect.y+ManHW))
           &&IsHero==0&&IsFly==0){
            Mix_PlayChannel(-1,SoundBad,0);
            score-=300;
            Life--;
            IsHero=1;
            StartHero=SDL_GetTicks();
        }

        if(((Barrier_3_Rect.x>=ManRect.x&&Barrier_3_Rect.x<=ManRect.x+50&&Barrier_3_Rect.y+SubjectHW>=ManRect.y&&Barrier_3_Rect.y<=ManRect.y+ManHW)
            ||(Barrier_5_Rect.x>=ManRect.x&&Barrier_5_Rect.x<=ManRect.x+50&&Barrier_5_Rect.y+SubjectHW>=ManRect.y&&Barrier_5_Rect.y<=ManRect.y+ManHW)
            ||(Barrier_8_Rect.x>=ManRect.x&&Barrier_8_Rect.x<=ManRect.x+50&&Barrier_8_Rect.y+SubjectHW>=ManRect.y&&Barrier_8_Rect.y<=ManRect.y+ManHW)
            ||(Barrier_10_Rect.x>=ManRect.x&&Barrier_10_Rect.x<=ManRect.x+50&&Barrier_10_Rect.y+SubjectHW>=ManRect.y&&Barrier_10_Rect.y<=ManRect.y+ManHW))
           &&IsHero==0&&IsDown==0){
            Mix_PlayChannel(-1,SoundBad,0);
            score-=300;
            Life--;
            IsHero=1;
            StartHero=SDL_GetTicks();
        }
        //game over
        if(Life==0){
            SDL_Delay(1000);
            PRINTGAMEOVER();
            quit=1;
        }
        SDL_RenderPresent(Renderer);
        Interact();
// *  * * * ** * * * * * print * * * * * * *** * * * * *
        PRINTSCORE();
        PRINTLIFE();
        DureTime=SDL_GetTicks()-StartPlay;
        SDL_Delay(20);
    }
}
void StandBarrier(){
    // * * * * * * * * 防撞击
    int *Barriers[17][2]={&BarrierRect.x,&BarrierRect.y,
                          &Barrier_1_Rect.x,&Barrier_1_Rect.y,
                          &Barrier_2_Rect.x,&Barrier_2_Rect.y,
                          &Barrier_3_Rect.x,&Barrier_3_Rect.y,
                          &Barrier_4_Rect.x,&Barrier_4_Rect.y,
                          &Barrier_5_Rect.x,&Barrier_5_Rect.y,
                          &Barrier_6_Rect.x,&Barrier_6_Rect.y,
                          &HumRect.x,&HumRect.y,
                          &Barrier_7_Rect.x,&Barrier_7_Rect.y,
                          &Bonus_1_Rect.x,&Bonus_1_Rect.y,
                          &Bonus_2_Rect.x,&Bonus_2_Rect.y,
                          &Bonus_3_Rect.x,&Bonus_3_Rect.y,
                          &Barrier_8_Rect.x,&Barrier_8_Rect.y,
                          &Barrier_9_Rect.x,&Barrier_9_Rect.y,
                          &Barrier_10_Rect.x,&Barrier_10_Rect.y,
                          &Barrier_11_Rect.x,&Barrier_11_Rect.y,
                          &Barrier_12_Rect.x,&Barrier_12_Rect.y};

    if(*Barriers[0][0]!=*Barriers[1][0]&&*Barriers[1][0]!=*Barriers[2][0]&&*Barriers[0][0]!=*Barriers[2][0]){
        int flag=0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(i==j){
                    continue;
                }
                if (*Barriers[i][1]-*Barriers[j][0]>ManHW+20){
                    flag=1;
                    i=3;
                    break;
                }
            }
        }
        if(flag==0&&*Barriers[0][1]<-10){
            *Barriers[0][1]-=ManHW+20;
        }
    }

    for (int i = 0; i < 17; ++i) {
        if(*Barriers[i][1]<-10){
            continue;
        }
        for (int j = 0; j < 17; ++j) {
            if(i==j||*Barriers[j][0]<0||*Barriers[j][1]>=0){
                continue;
            }
            if((*Barriers[i][1]-*Barriers[j][1]<ManHW+SubjectHW+50)&&*Barriers[i][0]==*Barriers[j][0]
               &&(*Barriers[i][1]-*Barriers[j][1]>=0)){
                *Barriers[j][1]-=ManHW+SubjectHW+50;
            }
        }
    }
// * * * * *    **  **** * * * ** * * * * * 防撞击
    //barrier 0
    if(Barrier_0_Lock==0&&DureTime>=500){
        barrier_0_time=SDL_GetTicks();
        BarrierRect.x= 500;
        DelayTime_0_barrier= Random(3);
        Barrier_0_Lock=1;//锁住
    }
    if(BarrierRect.y<=900 && (StartPlay-barrier_0_time) >= DelayTime_0_barrier && Barrier_0_Lock == 1){
        BarrierRect.y+=SPEED;
        SDL_RenderCopy(Renderer,BarrierTexture,NULL,&BarrierRect);
    } else if(BarrierRect.y>900){
        BarrierRect.y-=1200;
        Barrier_0_Lock=0;
    }
//********************* 1
    if(Barrier_1_Lock==0&&DureTime>=5790){
        barrier_1_time=SDL_GetTicks();
        DelayTime_1_barrier= Random(3);
        Barrier_1_Rect.x= 300;
        Barrier_1_Lock=1;//锁住
    }
    if(Barrier_1_Rect.y<=900 && (StartPlay-barrier_1_time) >= DelayTime_1_barrier && Barrier_1_Lock == 1){
        Barrier_1_Rect.y+=SPEED;
        SDL_RenderCopy(Renderer,Barrier_1_Texture,NULL,&Barrier_1_Rect);
    } else if(Barrier_1_Rect.y>900){
        Barrier_1_Rect.y-=1200;
        Barrier_1_Lock=0;
    }
    //************************** 2
    if(Barrier_2_Lock==0&&DureTime>=2500){
        barrier_2_time=SDL_GetTicks();
        DelayTime_2_barrier= Random(3);
        if(Barrier_2_Rect.y<-20){
            Barrier_2_Rect.x= Random(2);
        }
        Barrier_2_Lock=1;//锁住
    }
    if(Barrier_2_Rect.y<=900 && (StartPlay-barrier_2_time) >= DelayTime_2_barrier && Barrier_2_Lock == 1){
        Barrier_2_Rect.y+=SPEED;
        SDL_RenderCopy(Renderer,Barrier_2_Texture,NULL,&Barrier_2_Rect);
    } else if(Barrier_2_Rect.y>900){
        Barrier_2_Rect.y-=1200;
        Barrier_2_Lock=0;
    }

    //**************** 4 4
    if(Barrier_4_Lock==0){
        barrier_4_time=SDL_GetTicks();
        DelayTime_4_barrier= Random(3);
        Barrier_4_Rect.x= 100;
        Barrier_4_Lock=1;//锁住
    }
    if(Barrier_4_Rect.y<=900 && (StartPlay-barrier_4_time) >= DelayTime_4_barrier && Barrier_4_Lock == 1){
        Barrier_4_Rect.y+=SPEED;
        SDL_RenderCopy(Renderer,Barrier_4_Texture,NULL,&Barrier_4_Rect);
    } else if(Barrier_4_Rect.y>900){
        Barrier_4_Rect.y-=1000;
        Barrier_4_Lock=0;
    }
    // **** * * * *** * *    6
    if(Barrier_6_Lock==0){
        barrier_6_time=SDL_GetTicks();
        DelayTime_6_barrier= Random(3);
        if(Barrier_6_Rect.y<-SubjectHW){
            Barrier_6_Rect.x= Random(3);
        }
        Barrier_6_Lock=1;//锁住
    }
    if(Barrier_6_Rect.y<=900 && (StartPlay-barrier_6_time) >= DelayTime_6_barrier && Barrier_6_Lock == 1){
        Barrier_6_Rect.y+=SPEED;
        SDL_RenderCopy(Renderer,Barrier_6_Texture,NULL,&Barrier_6_Rect);
    } else if(Barrier_6_Rect.y>900){
        Barrier_6_Rect.y-=1000;
        Barrier_6_Lock=0;
    }
    //**********99*********
    if(Barrier_9_Lock==0&StartPlay>=2091){
        barrier_9_time=SDL_GetTicks();
        DelayTime_9_barrier= Random(3);
        Barrier_9_Rect.x= 500;
        Barrier_9_Lock=1;//锁住
    }
    if(Barrier_9_Rect.y<=900 && (StartPlay-barrier_9_time) >= DelayTime_9_barrier && Barrier_9_Lock == 1){
        Barrier_9_Rect.y+=SPEED;
        SDL_RenderCopy(Renderer,Barrier_9_Texture,NULL,&Barrier_9_Rect);
    } else if(Barrier_9_Rect.y>900){
        Barrier_9_Rect.y-=1000;
        Barrier_9_Lock=0;
    }
    //***11
    if(Barrier_11_Lock==0&StartPlay>=1791){
        barrier_11_time=SDL_GetTicks();
        DelayTime_11_barrier= 200;
        Barrier_11_Rect.x= 300;
        Barrier_11_Lock=1;//锁住
    }
    if(Barrier_11_Rect.y<=900 && (StartPlay-barrier_11_time) >= DelayTime_11_barrier && Barrier_11_Lock == 1){
        Barrier_11_Rect.y+=SPEED;
        SDL_RenderCopy(Renderer,Barrier_11_Texture,NULL,&Barrier_11_Rect);
    } else if(Barrier_11_Rect.y>900){
        Barrier_11_Rect.y-=1000;
        Barrier_11_Lock=0;
    }

//********************** 3
    if(Barrier_3_Lock==0){
        barrier_3_time=SDL_GetTicks();
        DelayTime_3_barrier= Random(3)*2;
        Barrier_3_Rect.x=500;

        Barrier_3_Lock=1;//锁住
    }
    if(Barrier_3_Rect.y<=900 && (StartPlay-barrier_3_time) >= DelayTime_3_barrier && Barrier_3_Lock == 1){
        Barrier_3_Rect.y+=SPEED;
        SDL_RenderCopy(Renderer,Barrier_3_Texture,NULL,&Barrier_3_Rect);
    } else if(Barrier_3_Rect.y>900){
        Barrier_3_Rect.y-=1000;
        Barrier_3_Lock=0;
    }
// * * *** * * * ** *   5
    if(Barrier_5_Lock==0){
        barrier_5_time=SDL_GetTicks();
        DelayTime_5_barrier= Random(3);
        if(Barrier_5_Rect.y<-SubjectHW){
            Barrier_5_Rect.x= Random(3);
        }
        Barrier_5_Lock=1;//锁住
    }
    if(Barrier_5_Rect.y<=900 && (StartPlay-barrier_5_time) >= DelayTime_5_barrier && Barrier_5_Lock == 1){
        Barrier_5_Rect.y+=SPEED;
        SDL_RenderCopy(Renderer,Barrier_5_Texture,NULL,&Barrier_5_Rect);
    } else if(Barrier_5_Rect.y>900){
        Barrier_5_Rect.y-=1000;
        Barrier_5_Lock=0;
    }

//**8*8*8*888888888888
    if(Barrier_8_Lock==0&&DureTime>=1008){
        barrier_8_time=SDL_GetTicks();
        DelayTime_8_barrier= Random(3);
        if(Barrier_8_Rect.y<-SubjectHW){
            Barrier_8_Rect.x= 100;
        }
        Barrier_8_Lock=1;//锁住
    }
    if(Barrier_8_Rect.y<=900 && (StartPlay-barrier_8_time) >= DelayTime_8_barrier && Barrier_8_Lock == 1){
        Barrier_8_Rect.y+=SPEED;
        SDL_RenderCopy(Renderer,Barrier_8_Texture,NULL,&Barrier_8_Rect);
    } else if(Barrier_8_Rect.y>900){
        Barrier_8_Rect.y-=1000;
        Barrier_8_Lock=0;
    }
//10
    if(Barrier_10_Lock==0&&DureTime>=1808){
        barrier_10_time=SDL_GetTicks();
        DelayTime_10_barrier= Random(3);
        if(Barrier_10_Rect.y<-SubjectHW){
            Barrier_10_Rect.x= 300;
        }
        Barrier_10_Lock=1;//锁住
    }
    if(Barrier_10_Rect.y<=900 && (StartPlay-barrier_10_time) >= DelayTime_10_barrier && Barrier_10_Lock == 1){
        Barrier_10_Rect.y+=SPEED;
        SDL_RenderCopy(Renderer,Barrier_10_Texture,NULL,&Barrier_10_Rect);
    } else if(Barrier_10_Rect.y>900){
        Barrier_10_Rect.y-=1000;
        Barrier_10_Lock=0;
    }
    SDL_RenderPresent(Renderer);
}
void Interact() {
    SDL_Event WAIT;
    int quit_wait=0;
    while (SDL_PollEvent(&inEvent)) {
        switch (inEvent.type) {//键盘交互
            case SDL_QUIT:
                QUIT();
                break;
            case SDL_KEYDOWN:
                printf("%lld\n", ran);
                switch (inEvent.key.keysym.sym) {

                    // 暂停
                    case SDLK_SPACE:
                        Mix_HaltMusic();
                        Wait_Z_Surface= TTF_RenderUTF8_Blended(Wait_Z_Font,"press space to continue",Wait_Z_Color);
                        Wait_Z_Texture= SDL_CreateTextureFromSurface(Renderer,Wait_Z_Surface);
                        Wait_Z_Rect.x=72;
                        Wait_Z_Rect.y=350;
                        Wait_Z_Rect.h=Wait_Z_Surface->h;
                        Wait_Z_Rect.w=Wait_Z_Surface->w;
                        SDL_RenderCopy(Renderer,Wait_Z_Texture,NULL,&Wait_Z_Rect);
                        SDL_RenderPresent(Renderer);
                        while (SDL_WaitEvent(&WAIT) && quit_wait == 0){
                            switch (WAIT.type) {
                                case SDL_QUIT:
                                    QUIT();
                                    break;
                                case SDL_KEYDOWN:
                                    switch (WAIT.key.keysym.sym) {
                                        case SDLK_SPACE:
                                            Mix_PlayMusic(Bgm,-1);
                                            quit_wait=1;
                                            break;
                                    }
                            }
                        }
                        break;
                    case SDLK_a:
                        ran++;
                        if (ManRect.x-200<0){
                            break;
                        }
                        ManRect.x -= 200;
                        break;
                    case SDLK_ESCAPE:
                        QUIT();
                        break;
                    case SDLK_d:
                        if (ManRect.x+200>640){
                            break;
                        }
                        ManRect.x += 200;
                        break;
                    case SDLK_w:
                        IsFly=1;// is flying
                        StartFly=SDL_GetTicks();
                        break;
                    case SDLK_s:
                        IsDown=1;
                        StartDown=SDL_GetTicks();
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
        break;
    }
}
void PRINTGAMEOVER(){
    int open=0;
    record_score=record_score>score?record_score:score;
    printf("%lld",record_score);
    Mix_HaltMusic();
    SDL_RenderCopy(Renderer,EndBackGroundTexture,NULL,NULL);

    GameOverSurface= TTF_RenderUTF8_Blended(GameOverFont,"Game over!",end_color);
    GameOverTexture= SDL_CreateTextureFromSurface(Renderer,GameOverSurface);
    GameOverRect.x=52;
    GameOverRect.y=184;
    GameOverRect.h=GameOverSurface->h;
    GameOverRect.w=GameOverSurface->w;
    SDL_RenderCopy(Renderer,GameOverTexture,NULL,&GameOverRect);
//***********************  只用 score 与 score_z_
    Score_Z_Surface = TTF_RenderUTF8_Blended(Score_Z_Font,"SCORE:",end_color);
    Score_Z_Texture = SDL_CreateTextureFromSurface(Renderer,Score_Z_Surface);
    Score_Z_Rect.x =224;
    Score_Z_Rect.y= 384;
    Score_Z_Rect.w=Score_Z_Surface->w;
    Score_Z_Rect.h=Score_Z_Surface->h;
    SDL_RenderCopy(Renderer,Score_Z_Texture,NULL,&Score_Z_Rect);

    char SCORE[1000];
    itoa(score,SCORE,10);
    ScoreSurface = TTF_RenderUTF8_Blended(ScoreFont,SCORE,end_color);
    ScoreTexture = SDL_CreateTextureFromSurface(Renderer,ScoreSurface);
    ScoreRect.x =410;
    ScoreRect.y= 384;
    ScoreRect.w=ScoreSurface->w;
    ScoreRect.h=ScoreSurface->h;
    SDL_RenderCopy(Renderer,ScoreTexture,NULL,&ScoreRect);
//--------------------------------
    Score_Z_Surface = TTF_RenderUTF8_Blended(Score_Z_Font,"RECORD:",end_color);
    Score_Z_Texture = SDL_CreateTextureFromSurface(Renderer,Score_Z_Surface);
    Score_Z_Rect.x =224;
    Score_Z_Rect.y= 494;
    Score_Z_Rect.w=Score_Z_Surface->w;
    Score_Z_Rect.h=Score_Z_Surface->h;
    SDL_RenderCopy(Renderer,Score_Z_Texture,NULL,&Score_Z_Rect);
    //................
    char Record[10000];
    itoa(record_score,Record,10);
    ScoreSurface = TTF_RenderUTF8_Blended(ScoreFont,Record,end_color);
    ScoreTexture = SDL_CreateTextureFromSurface(Renderer,ScoreSurface);
    ScoreRect.x =410;
    ScoreRect.y= 494;
    ScoreRect.w=ScoreSurface->w;
    ScoreRect.h=ScoreSurface->h;
    SDL_RenderCopy(Renderer,ScoreTexture,NULL,&ScoreRect);
//---------------
    if(score==record_score){
        open=1;
        break_record();
    } else{
        BriefSurface = TTF_RenderUTF8_Blended(BriefFont,"you don't break the record !",BriefColor);
        BriefTexture = SDL_CreateTextureFromSurface(Renderer,BriefSurface);
        BriefRect.x =185;
        BriefRect.y= 564;
        BriefRect.w=BriefSurface->w;
        BriefRect.h=BriefSurface->h;
        SDL_RenderCopy(Renderer,BriefTexture,NULL,&BriefRect);


        BriefRect.x =185;
        BriefRect.y= 566;
        BriefRect.w=BriefSurface->w;
        BriefRect.h=BriefSurface->h;
        SDL_RenderCopy(Renderer,BriefTexture,NULL,&BriefRect);
        SDL_RenderPresent(Renderer);

        Mix_HaltMusic();
        Mix_PlayMusic(notbreak,-1);
        quit_or_play();
    }
    SDL_Event End;
    while(SDL_WaitEvent(&End)){
        switch (End.type) {
            case SDL_QUIT:
                QUIT();
            case SDL_MOUSEBUTTONDOWN:
                if(open==1&&End.button.x>=409&&End.button.y>=634&&End.button.x<=609&&End.button.y<=773){
                    switch (ran%3) {
                        case 0:
                            SDL_RenderCopy(Renderer,Gift_1_Texture,NULL,&Gift_1_Rect);
                            break;
                        case 1:
                            SDL_RenderCopy(Renderer,Gift_2_Texture,NULL,&Gift_1_Rect);
                            break;
                        case 2:
                            SDL_RenderCopy(Renderer,Gift_3_Texture,NULL,&Gift_1_Rect);
                            break;
                    }
                    SDL_RenderPresent(Renderer);
                    quit_or_play();
                }
                printf("(%d,%d)\n",End.button.x,End.button.y);
                break;
            case SDL_KEYDOWN:
                switch (End.key.keysym.sym) {
                    case SDLK_1:
                        Life=1;
                        score=0;
                        int *Barriers[17][2]={&BarrierRect.x,&BarrierRect.y,
                                              &Barrier_1_Rect.x,&Barrier_1_Rect.y,
                                              &Barrier_2_Rect.x,&Barrier_2_Rect.y,
                                              &Barrier_3_Rect.x,&Barrier_3_Rect.y,
                                              &Barrier_4_Rect.x,&Barrier_4_Rect.y,
                                              &Barrier_5_Rect.x,&Barrier_5_Rect.y,
                                              &Barrier_6_Rect.x,&Barrier_6_Rect.y,
                                              &HumRect.x,&HumRect.y,
                                              &Barrier_7_Rect.x,&Barrier_7_Rect.y,
                                              &Bonus_1_Rect.x,&Bonus_1_Rect.y,
                                              &Bonus_2_Rect.x,&Bonus_2_Rect.y,
                                              &Bonus_3_Rect.x,&Bonus_3_Rect.y,
                                              &Barrier_8_Rect.x,&Barrier_8_Rect.y,
                                              &Barrier_9_Rect.x,&Barrier_9_Rect.y,
                                              &Barrier_10_Rect.x,&Barrier_10_Rect.y,
                                              &Barrier_11_Rect.x,&Barrier_11_Rect.y,
                                              &Barrier_12_Rect.x,&Barrier_12_Rect.y};
                        for (int i = 0; i < 17; ++i) {
                            *Barriers[i][1]-=1000;
                        }
                        SDL_RenderClear(Renderer);
                        PLAY();
                        break;
                    case SDLK_2:
                        QUIT();
                        break;
                    default:
                        break;
                }
        }
    }
}
void PLAY(){
    Mix_PlayMusic(Bgm,-1);//暂停用SDL_HaltMusic or Channel

    StartPlay =SDL_GetTicks();
    printf("You are in the running!\n");
    SDL_RenderClear(Renderer);//产生图片
    SDL_RenderCopy(Renderer,PlayBackGroundTexture,NULL,NULL);
    SDL_RenderPresent(Renderer);//刷新

    ManRect.x=290;
    ManRect.y=700;
    ManRect.w=ManHW;
    ManRect.h=ManHW;
    StandHum();
}
void PRINTLIFE(){
    char LIFE[100];
    itoa(Life,LIFE,10);
    LifeSurface= TTF_RenderUTF8_Blended(LifeFont,LIFE,LifeColor);
    LifeTexture= SDL_CreateTextureFromSurface(Renderer,LifeSurface);
    LifeRect.x=600;
    LifeRect.y=70;
    LifeRect.h=LifeSurface->h;
    LifeRect.w=LifeSurface->w;
    SDL_RenderCopy(Renderer,LifeTexture,NULL,&LifeRect);

    Life_Z_Surface= TTF_RenderUTF8_Blended(Life_Z_Font,"LIFE:",Life_Z_Color);
    Life_Z_Texture= SDL_CreateTextureFromSurface(Renderer,Life_Z_Surface);
    Life_Z_Rect.x=500;
    Life_Z_Rect.y=70;
    Life_Z_Rect.h=Life_Z_Surface->h;
    Life_Z_Rect.w=Life_Z_Surface->w;
    SDL_RenderCopy(Renderer,Life_Z_Texture,NULL,&Life_Z_Rect);
    SDL_RenderPresent(Renderer);
}
void PRINTSCORE(){
    char SCORE[1000];
    score+=(SPEED/3);
    itoa(score,SCORE,10);
    ScoreSurface = TTF_RenderUTF8_Blended(ScoreFont,SCORE,FontColor);
    ScoreTexture = SDL_CreateTextureFromSurface(Renderer,ScoreSurface);
    ScoreRect.x =600;
    ScoreRect.y= 24;
    ScoreRect.w=ScoreSurface->w;
    ScoreRect.h=ScoreSurface->h;
    SDL_RenderCopy(Renderer,ScoreTexture,NULL,&ScoreRect);

    Score_Z_Surface = TTF_RenderUTF8_Blended(Score_Z_Font,"SCORE:",Score_Z_Color);
    Score_Z_Texture = SDL_CreateTextureFromSurface(Renderer,Score_Z_Surface);
    Score_Z_Rect.x =450;
    Score_Z_Rect.y= 24;
    Score_Z_Rect.w=Score_Z_Surface->w;
    Score_Z_Rect.h=Score_Z_Surface->h;
    SDL_RenderCopy(Renderer,Score_Z_Texture,NULL,&Score_Z_Rect);
    SDL_RenderPresent(Renderer);

}
void break_record(){
    Mix_PlayMusic(breakrecord,-1);
    BriefSurface = TTF_RenderUTF8_Blended(BriefFont,"Paprika send an envelope to u,click it to unfold",BriefColor);
    BriefTexture = SDL_CreateTextureFromSurface(Renderer,BriefSurface);
    BriefRect.x =25;
    BriefRect.y= 564;
    BriefRect.w=BriefSurface->w;
    BriefRect.h=BriefSurface->h;
    SDL_RenderCopy(Renderer,BriefTexture,NULL,&BriefRect);

    BriefSurface = TTF_RenderUTF8_Blended(BriefFont,"Paprika send an envelope to u,click it to unfold",BriefColor);
    BriefTexture = SDL_CreateTextureFromSurface(Renderer,BriefSurface);
    BriefRect.x =25;
    BriefRect.y= 566;
    BriefRect.w=BriefSurface->w;
    BriefRect.h=BriefSurface->h;

    SDL_RenderCopy(Renderer,BriefTexture,NULL,&BriefRect);
// *********************************************************************** 👆加粗
    BreakRecordRect.x =150;
    BreakRecordRect.y= 634;
    BreakRecordRect.w=190;
    BreakRecordRect.h=170;
    SDL_RenderCopy(Renderer,BreakRecordTexture,NULL,&BreakRecordRect);

    EnvelopeRect.x =410;
    EnvelopeRect.y= 634;
    EnvelopeRect.w=200;
    EnvelopeRect.h=140;

    SDL_RenderCopy(Renderer,EnvelopeTexture,NULL,&EnvelopeRect);
    SDL_RenderPresent(Renderer);

}
void quit_or_play(){
    Score_Z_Surface = TTF_RenderUTF8_Blended(Score_Z_Font,"press 1 to play again",end_color);
    Score_Z_Texture = SDL_CreateTextureFromSurface(Renderer,Score_Z_Surface);

    Score_Z_Rect.x =114;
    Score_Z_Rect.y= 704;
    Score_Z_Rect.w=Score_Z_Surface->w;
    Score_Z_Rect.h=Score_Z_Surface->h;

    SDL_RenderCopy(Renderer,Score_Z_Texture,NULL,&Score_Z_Rect);

    Score_Z_Surface = TTF_RenderUTF8_Blended(Score_Z_Font,"press 2 to quit",end_color);
    Score_Z_Texture = SDL_CreateTextureFromSurface(Renderer,Score_Z_Surface);

    Score_Z_Rect.x =114;
    Score_Z_Rect.y= 754;
    Score_Z_Rect.w=Score_Z_Surface->w;
    Score_Z_Rect.h=Score_Z_Surface->h;

    SDL_RenderCopy(Renderer,Score_Z_Texture,NULL,&Score_Z_Rect);
    SDL_RenderPresent(Renderer);
}
