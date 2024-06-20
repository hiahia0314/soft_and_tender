//
// Created by 23125 on 2023/12/26.
//

#ifndef BIG_HOMEWORK_COMMON_H
#define BIG_HOMEWORK_COMMON_H

unsigned long long int ran=16;
#define ManHW 80
#define SubjectHW 60
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL_mixer.h>

int Random(int t);
void PLAY();
void Interact();
void StandHum();
void StandBarrier();
void LOAD();
void QUIT();
void PRINTLIFE();
void PRINTGAMEOVER();
void PRINTSCORE();
void break_record();
void quit_or_play();

int SPEED=1;
long long int score;

long long int record_score;
int Life=1;

unsigned long long int StartHero;
unsigned long long int DureHero;
int IsHero=0;//0表示没有无敌

unsigned long long int StartFly;
unsigned long long int DureFly;
int IsFly=0;//not flying

unsigned long long int StartDown;
unsigned long long int DureDown;
int IsDown=0;

unsigned long long int StartPlay;
unsigned long long int DureTime;

/*
 * barrier 4,6 是sky
 * barrier 7 是 hero
 * 1，2，0是Barr
 */

unsigned long long int barrier_0_time;
int DelayTime_0_barrier=0;
int Barrier_0_Lock=0;

unsigned long long int barrier_1_time;
int DelayTime_1_barrier=0;
int Barrier_1_Lock=0;

unsigned long long int barrier_2_time;
int DelayTime_2_barrier=0;
int Barrier_2_Lock=0;

unsigned long long int barrier_3_time;
int DelayTime_3_barrier=0;
int Barrier_3_Lock=0;

unsigned long long int barrier_4_time;
int DelayTime_4_barrier=0;
int Barrier_4_Lock=0;

unsigned long long int barrier_5_time;
int DelayTime_5_barrier=0;
int Barrier_5_Lock=0;

unsigned long long int barrier_6_time;//sky
int DelayTime_6_barrier=0;
int Barrier_6_Lock=0;


unsigned long long int barrier_8_time;
int DelayTime_8_barrier=0;
int Barrier_8_Lock=0;

unsigned long long int barrier_9_time;//sky
int DelayTime_9_barrier=0;
int Barrier_9_Lock=0;

unsigned long long int barrier_10_time;//sky
int DelayTime_10_barrier=0;
int Barrier_10_Lock=0;

unsigned long long int barrier_11_time;//sky
int DelayTime_11_barrier=0;
int Barrier_11_Lock=0;

SDL_Event inEvent;//interact

SDL_Window *Window = NULL; //窗口
SDL_Renderer *Renderer=NULL; //画笔

SDL_Surface *FlySurface=NULL;//图片初始化fly
SDL_Texture *FlyTexture=NULL;
SDL_Rect FlyRect;

SDL_Surface *DownSurface=NULL;//图片初始化down
SDL_Texture *DownTexture=NULL;
SDL_Rect DownRect;

SDL_Surface *HeroSurface=NULL;//图片初始化hero
SDL_Texture *HeroTexture=NULL;
SDL_Rect HeroRect;

SDL_Surface *MainBackGroundSurface=NULL;//图片初始化
SDL_Texture *MainBackGroundTexture=NULL;
SDL_Rect MainBackGroundRect;

SDL_Surface *EndBackGroundSurface=NULL;//结束背景
SDL_Texture *EndBackGroundTexture=NULL;

SDL_Surface *PlayBackGroundSurface=NULL;//图片初始化  surface texture rect
SDL_Texture *PlayBackGroundTexture=NULL;

SDL_Surface *IntroSurface=NULL;
SDL_Texture *IntroTexture=NULL;//brief introduction


SDL_Surface *ManSurface=NULL;//人物
SDL_Texture *ManTexture=NULL;
SDL_Rect ManRect;

SDL_Surface *BreakRecordSurface=NULL;//人物
SDL_Texture *BreakRecordTexture=NULL;
SDL_Rect BreakRecordRect;

SDL_Surface *EnvelopeSurface=NULL;//人物
SDL_Texture *EnvelopeTexture=NULL;
SDL_Rect EnvelopeRect;

SDL_Surface *Gift_1_Surface=NULL;//人物
SDL_Texture *Gift_1_Texture=NULL;
SDL_Rect Gift_1_Rect;

SDL_Surface *Gift_2_Surface=NULL;//人物
SDL_Texture *Gift_2_Texture=NULL;

SDL_Surface *Gift_3_Surface=NULL;//人物
SDL_Texture *Gift_3_Texture=NULL;


SDL_Surface *Bonus_1_Surface=NULL;//
SDL_Texture *Bonus_1_Texture=NULL;
SDL_Rect Bonus_1_Rect;

SDL_Surface *Bonus_2_Surface=NULL;//
SDL_Texture *Bonus_2_Texture=NULL;
SDL_Rect Bonus_2_Rect;

SDL_Surface *Bonus_3_Surface=NULL;//
SDL_Texture *Bonus_3_Texture=NULL;
SDL_Rect Bonus_3_Rect;

SDL_Surface *HumSurface=NULL;//🍔
SDL_Texture *HumTexture=NULL;
SDL_Rect HumRect;
// many barriers * * *** * * * * * *  ** * * * *
SDL_Surface *BarrierSurface=NULL;//barrier
SDL_Texture *BarrierTexture=NULL;
SDL_Rect BarrierRect;

SDL_Surface *Barrier_1_Surface=NULL;//barrier
SDL_Texture *Barrier_1_Texture=NULL;
SDL_Rect Barrier_1_Rect;

SDL_Surface *Barrier_2_Surface=NULL;//barrier
SDL_Texture *Barrier_2_Texture=NULL;
SDL_Rect Barrier_2_Rect;

SDL_Surface *Barrier_3_Surface=NULL;//barrier
SDL_Texture *Barrier_3_Texture=NULL;
SDL_Rect Barrier_3_Rect;

SDL_Surface *Barrier_4_Surface=NULL;//barrier
SDL_Texture *Barrier_4_Texture=NULL;
SDL_Rect Barrier_4_Rect;

SDL_Surface *Barrier_5_Surface=NULL;//barrier
SDL_Texture *Barrier_5_Texture=NULL;
SDL_Rect Barrier_5_Rect;

SDL_Surface *Barrier_6_Surface=NULL;//barrier
SDL_Texture *Barrier_6_Texture=NULL;
SDL_Rect Barrier_6_Rect;          //sky

SDL_Surface *Barrier_7_Surface=NULL;//barrier hero thing
SDL_Texture *Barrier_7_Texture=NULL;
SDL_Rect Barrier_7_Rect;

SDL_Surface *Barrier_8_Surface=NULL;//barrier
SDL_Texture *Barrier_8_Texture=NULL;
SDL_Rect Barrier_8_Rect;          //ky

SDL_Surface *Barrier_9_Surface=NULL;//barrier hero thing
SDL_Texture *Barrier_9_Texture=NULL;
SDL_Rect Barrier_9_Rect;

SDL_Surface *Barrier_10_Surface=NULL;//barrier hero thing
SDL_Texture *Barrier_10_Texture=NULL;
SDL_Rect Barrier_10_Rect;

SDL_Surface *Barrier_11_Surface=NULL;//barrier
SDL_Texture *Barrier_11_Texture=NULL;
SDL_Rect Barrier_11_Rect;          //ky

SDL_Surface *Barrier_12_Surface=NULL;//barrier hero thing
SDL_Texture *Barrier_12_Texture=NULL;
SDL_Rect Barrier_12_Rect;

//****      score     *******************
TTF_Font *ScoreFont = NULL;    // / /  s数字
SDL_Surface *ScoreSurface=NULL;
SDL_Texture *ScoreTexture=NULL;
SDL_Rect ScoreRect;
SDL_Color FontColor = {0,0,0,0};

TTF_Font *Score_Z_Font = NULL;  //字
SDL_Surface *Score_Z_Surface=NULL;
SDL_Texture *Score_Z_Texture=NULL;
SDL_Rect Score_Z_Rect;
SDL_Color Score_Z_Color = {0,0,0,0};

SDL_Color end_color={255,255,255,255};

//*****   *********         life    **********
TTF_Font *LifeFont = NULL;
SDL_Surface *LifeSurface=NULL;
SDL_Texture *LifeTexture=NULL;
SDL_Rect LifeRect;
SDL_Color LifeColor = {0,0,0,0};

TTF_Font *Life_Z_Font = NULL;
SDL_Surface *Life_Z_Surface=NULL;
SDL_Texture *Life_Z_Texture=NULL;
SDL_Rect Life_Z_Rect;
SDL_Color Life_Z_Color = {0,0,0,0};

//***************     gameover      *****************

TTF_Font *GameOverFont = NULL;
SDL_Surface *GameOverSurface=NULL; //  game over 字幕
SDL_Texture *GameOverTexture=NULL;
SDL_Rect GameOverRect;
SDL_Color GameOverColor = {255,255,255,255};

TTF_Font *BriefFont = NULL;
SDL_Surface *BriefSurface=NULL;
SDL_Texture *BriefTexture=NULL;
SDL_Rect BriefRect;
SDL_Color BriefColor = {250,250,250,250};

TTF_Font *Wait_Z_Font = NULL;
SDL_Surface *Wait_Z_Surface=NULL;
SDL_Texture *Wait_Z_Texture=NULL;
SDL_Rect Wait_Z_Rect;
SDL_Color Wait_Z_Color = {0,0,0,0};

Mix_Music *Bgm;
Mix_Chunk *SoundGood;
Mix_Chunk *SoundBad;

Mix_Music *breakrecord;
Mix_Music *notbreak;
void LOAD(){////加载图片
    MainBackGroundSurface= IMG_Load("image/starter.jpg");//加载图片
    MainBackGroundTexture= SDL_CreateTextureFromSurface(Renderer,MainBackGroundSurface);
    MainBackGroundRect.x=0;
    MainBackGroundRect.y=0;//出现的起始位置
    MainBackGroundRect.w=MainBackGroundSurface->w;
    MainBackGroundRect.h=MainBackGroundSurface->h;

    FlySurface= IMG_Load("image/fly.png");
    FlyTexture= SDL_CreateTextureFromSurface(Renderer,FlySurface);

    DownSurface= IMG_Load("image/down.png");
    DownTexture= SDL_CreateTextureFromSurface(Renderer,DownSurface);

    HeroSurface= IMG_Load("image/hero.jpg");
    HeroTexture= SDL_CreateTextureFromSurface(Renderer,HeroSurface);

    PlayBackGroundSurface= IMG_Load("image/paodao.png");
    PlayBackGroundTexture= SDL_CreateTextureFromSurface(Renderer,PlayBackGroundSurface);

    EndBackGroundSurface= IMG_Load("image/end.png");
    EndBackGroundTexture= SDL_CreateTextureFromSurface(Renderer,EndBackGroundSurface);

    HumSurface= IMG_Load("image/hum.jpg");
    HumTexture= SDL_CreateTextureFromSurface(Renderer,HumSurface);

    Bonus_1_Surface= IMG_Load("image/bonus.jpg");
    Bonus_1_Texture= SDL_CreateTextureFromSurface(Renderer, Bonus_1_Surface);
    Bonus_1_Rect.y=-3*SubjectHW;
    Bonus_1_Rect.h=SubjectHW;
    Bonus_1_Rect.w=SubjectHW;

    Bonus_2_Surface= IMG_Load("image/bonus.jpg");
    Bonus_2_Texture= SDL_CreateTextureFromSurface(Renderer, Bonus_2_Surface);
    Bonus_2_Rect.y=-3*SubjectHW;
    Bonus_2_Rect.h=SubjectHW;
    Bonus_2_Rect.w=SubjectHW;


    Bonus_3_Surface= IMG_Load("image/bonus.jpg");
    Bonus_3_Texture= SDL_CreateTextureFromSurface(Renderer, Bonus_3_Surface);
    Bonus_3_Rect.y=-3*SubjectHW;
    Bonus_3_Rect.h=SubjectHW;
    Bonus_3_Rect.w=SubjectHW;


    BreakRecordSurface= IMG_Load("image/look.png");
    BreakRecordTexture= SDL_CreateTextureFromSurface(Renderer,BreakRecordSurface);

    EnvelopeSurface= IMG_Load("image/envelope.jpg");
    EnvelopeTexture= SDL_CreateTextureFromSurface(Renderer,EnvelopeSurface);

    Gift_1_Surface= IMG_Load("image/thanks1.png");
    Gift_1_Texture= SDL_CreateTextureFromSurface(Renderer,Gift_1_Surface);
    Gift_1_Rect.x=90;
    Gift_1_Rect.y=90;
    Gift_1_Rect.h=665;
    Gift_1_Rect.w=489;

    Gift_2_Surface= IMG_Load("image/thanks2.png");
    Gift_2_Texture= SDL_CreateTextureFromSurface(Renderer,Gift_2_Surface);

    Gift_3_Surface= IMG_Load("image/thanks3.png");
    Gift_3_Texture= SDL_CreateTextureFromSurface(Renderer,Gift_3_Surface);

    ManSurface= IMG_Load("image/paprika.jpg");
    ManTexture= SDL_CreateTextureFromSurface(Renderer,ManSurface);
    //barrier init
    BarrierSurface= IMG_Load("image/barrier.jpg");
    BarrierTexture= SDL_CreateTextureFromSurface(Renderer,BarrierSurface);
    BarrierRect.y=-3*SubjectHW;
    BarrierRect.h=SubjectHW;
    BarrierRect.w=SubjectHW;

    Barrier_1_Surface= IMG_Load("image/barrier.jpg");
    Barrier_1_Texture= SDL_CreateTextureFromSurface(Renderer,Barrier_1_Surface);
    Barrier_1_Rect.y=-SubjectHW;
    Barrier_1_Rect.h=SubjectHW;
    Barrier_1_Rect.w=SubjectHW;

    Barrier_2_Surface= IMG_Load("image/barrier.jpg");
    Barrier_2_Texture= SDL_CreateTextureFromSurface(Renderer, Barrier_2_Surface);
    Barrier_2_Rect.y=-SubjectHW;
    Barrier_2_Rect.h=SubjectHW;
    Barrier_2_Rect.w=SubjectHW;


    Barrier_11_Surface= IMG_Load("image/sky.jpg");
    Barrier_11_Texture= SDL_CreateTextureFromSurface(Renderer, Barrier_11_Surface);
    Barrier_11_Rect.y=-3*SubjectHW;
    Barrier_11_Rect.h=SubjectHW;
    Barrier_11_Rect.w=SubjectHW;

    Barrier_9_Surface= IMG_Load("image/sky.jpg");
    Barrier_9_Texture= SDL_CreateTextureFromSurface(Renderer, Barrier_9_Surface);
    Barrier_9_Rect.y=-3*SubjectHW;
    Barrier_9_Rect.h=SubjectHW;
    Barrier_9_Rect.w=SubjectHW;

    Barrier_4_Surface= IMG_Load("image/sky.jpg");
    Barrier_4_Texture= SDL_CreateTextureFromSurface(Renderer, Barrier_4_Surface);
    Barrier_4_Rect.y=-2*SubjectHW;
    Barrier_4_Rect.h=SubjectHW;
    Barrier_4_Rect.w=SubjectHW;

    Barrier_6_Surface= IMG_Load("image/sky.jpg");
    Barrier_6_Texture= SDL_CreateTextureFromSurface(Renderer, Barrier_6_Surface);
    Barrier_6_Rect.y=-3*SubjectHW;
    Barrier_6_Rect.h=SubjectHW;
    Barrier_6_Rect.w=SubjectHW;

    Barrier_3_Surface= IMG_Load("image/water.jpg");
    Barrier_3_Texture= SDL_CreateTextureFromSurface(Renderer, Barrier_3_Surface);
    Barrier_3_Rect.y=-2*SubjectHW;
    Barrier_3_Rect.h=SubjectHW;
    Barrier_3_Rect.w=SubjectHW;

    Barrier_5_Surface= IMG_Load("image/water.jpg");
    Barrier_5_Texture= SDL_CreateTextureFromSurface(Renderer, Barrier_5_Surface);
    Barrier_5_Rect.y=-3*SubjectHW;
    Barrier_5_Rect.h=SubjectHW;
    Barrier_5_Rect.w=SubjectHW;

    Barrier_8_Surface= IMG_Load("image/water.jpg");
    Barrier_8_Texture= SDL_CreateTextureFromSurface(Renderer, Barrier_8_Surface);
    Barrier_8_Rect.y=-3*SubjectHW;
    Barrier_8_Rect.h=SubjectHW;
    Barrier_8_Rect.w=SubjectHW;

    Barrier_10_Surface= IMG_Load("image/water.jpg");
    Barrier_10_Texture= SDL_CreateTextureFromSurface(Renderer, Barrier_10_Surface);
    Barrier_10_Rect.y=-3*SubjectHW;
    Barrier_10_Rect.h=SubjectHW;
    Barrier_10_Rect.w=SubjectHW;


    Barrier_7_Surface= IMG_Load("image/herothing.png");
    Barrier_7_Texture= SDL_CreateTextureFromSurface(Renderer, Barrier_7_Surface);
    Barrier_7_Rect.y=-3*SubjectHW;
    Barrier_7_Rect.h=SubjectHW;
    Barrier_7_Rect.w=SubjectHW;

    Barrier_12_Surface= IMG_Load("image/decrease.jpg");
    Barrier_12_Texture= SDL_CreateTextureFromSurface(Renderer, Barrier_12_Surface);
    Barrier_12_Rect.y=-3*SubjectHW;
    Barrier_12_Rect.h=SubjectHW;
    Barrier_12_Rect.w=SubjectHW;

    LifeFont=TTF_OpenFont("font/ARIALNBI.TTF",40);
    ScoreFont=TTF_OpenFont("font/ARIALNBI.TTF",40);
    Score_Z_Font= TTF_OpenFont("font/ARIALNBI.TTF",40);//score
    Life_Z_Font= TTF_OpenFont("font/ARIALNBI.TTF",40);//life
    Wait_Z_Font= TTF_OpenFont("font/unique.TTF",60);// press space to continue
    GameOverFont= TTF_OpenFont("font/unique.TTF",140);//game over
    BriefFont= TTF_OpenFont("font/unique.TTF",32);

    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,
                  MIX_DEFAULT_CHANNELS,2048);

    notbreak= Mix_LoadMUS("sound/notbreak.mp3");
    breakrecord= Mix_LoadMUS("sound/breakrecord.mp3");
    Bgm= Mix_LoadMUS("sound/bgm.mp3");
    SoundBad= Mix_LoadWAV("sound/bad.wav");
    SoundGood= Mix_LoadWAV("sound/good.wav");

}
void QUIT(){
    SDL_DestroyWindow(Window);
    SDL_DestroyRenderer(Renderer);

    SDL_FreeSurface(ScoreSurface);
    SDL_FreeSurface(MainBackGroundSurface);//free
    SDL_FreeSurface(PlayBackGroundSurface);
    SDL_FreeSurface(IntroSurface);
    SDL_FreeSurface(ManSurface);
    SDL_FreeSurface(FlySurface);
    SDL_FreeSurface(BarrierSurface);
    SDL_FreeSurface(Barrier_1_Surface);
    SDL_FreeSurface(Barrier_2_Surface);
    SDL_FreeSurface(Barrier_3_Surface);
    SDL_FreeSurface(Barrier_4_Surface);
    SDL_FreeSurface(Barrier_5_Surface);
    SDL_FreeSurface(Barrier_6_Surface);
    SDL_FreeSurface(Barrier_7_Surface);
    SDL_FreeSurface(DownSurface);
    SDL_FreeSurface(EndBackGroundSurface);
    SDL_FreeSurface(Wait_Z_Surface);
    SDL_FreeSurface(BreakRecordSurface);
    SDL_FreeSurface(EnvelopeSurface);
    SDL_FreeSurface(Gift_1_Surface);
    SDL_FreeSurface(Gift_2_Surface);
    SDL_FreeSurface(Gift_3_Surface);
    SDL_FreeSurface(Bonus_1_Surface);
    SDL_FreeSurface(Bonus_2_Surface);
    SDL_FreeSurface(Bonus_3_Surface);
    SDL_FreeSurface(Barrier_8_Surface);
    SDL_FreeSurface(Barrier_9_Surface);
    SDL_FreeSurface(Barrier_11_Surface);
    SDL_FreeSurface(Barrier_12_Surface);
    SDL_FreeSurface(Barrier_10_Surface);

    SDL_DestroyTexture(Barrier_10_Texture);
    SDL_DestroyTexture(Barrier_11_Texture);
    SDL_DestroyTexture(Barrier_12_Texture);
    SDL_DestroyTexture(Barrier_8_Texture);
    SDL_DestroyTexture(Barrier_8_Texture);
    SDL_DestroyTexture(Bonus_2_Texture);
    SDL_DestroyTexture(Bonus_3_Texture);
    SDL_DestroyTexture(Bonus_1_Texture);
    SDL_DestroyTexture(Gift_1_Texture);
    SDL_DestroyTexture(Gift_2_Texture);
    SDL_DestroyTexture(Gift_3_Texture);
    SDL_DestroyTexture(BreakRecordTexture);
    SDL_DestroyTexture(EnvelopeTexture);
    SDL_DestroyTexture(Wait_Z_Texture);
    SDL_DestroyTexture(EndBackGroundTexture);
    SDL_DestroyTexture(Barrier_7_Texture);
    SDL_DestroyTexture(DownTexture);
    SDL_DestroyTexture(Barrier_6_Texture);
    SDL_DestroyTexture(Barrier_4_Texture);
    SDL_DestroyTexture(Barrier_5_Texture);
    SDL_DestroyTexture(Barrier_3_Texture);
    SDL_DestroyTexture(BarrierTexture);
    SDL_DestroyTexture(Barrier_1_Texture);
    SDL_DestroyTexture(Barrier_2_Texture);
    SDL_DestroyTexture(FlyTexture);
    SDL_DestroyTexture(ManTexture);
    SDL_DestroyTexture(ScoreTexture);
    SDL_DestroyTexture(MainBackGroundTexture);
    SDL_DestroyTexture(PlayBackGroundTexture);
    SDL_DestroyTexture(IntroTexture);

    TTF_CloseFont(ScoreFont);
    TTF_CloseFont(LifeFont);
    TTF_CloseFont(GameOverFont);
    TTF_CloseFont(Score_Z_Font);
    TTF_CloseFont(Life_Z_Font);
    TTF_CloseFont(BriefFont);
    TTF_CloseFont(Wait_Z_Font);

    Mix_FreeMusic(Bgm);
    Mix_FreeMusic(notbreak);
    Mix_FreeMusic(breakrecord);
    Mix_FreeChunk(SoundGood);
    Mix_FreeChunk(SoundBad);

    SDL_Quit();
    TTF_Quit();
    IMG_Quit();
    Mix_Quit();
}
int Random(int t){
    ran++;
    switch (ran%t) {
        case 1:
            return 300;
        case 2:
            return 500;
        case 0:
            return 100;
        default:
            return  -100;
    }
}

#endif //BIG_HOMEWORK_COMMON_H

