#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int level, maxNumber, randomNumber, tries;
    char playAgain, guess[100];

    char easyLyrics[10][100] = {
        "Is this the real life? Is this just fantasy?",
        "We will, we will rock you!",
        "Billie Jean is not my lover, She's just a girl who claims that I am the one",
        "Hey Jude, don't make it bad. Take a sad song  make it better.",
        "Wake me up inside (I can't wake up) Wake me up insde (Save me)",
        "Olha que coisa mais linda, mais cheia de graça".
        "Yesterday, all my troubles seemed so far away",
        "Todos os dias quando acordo, não tenho mais o tempo que passou, mas tenho muito tempo, temos todo o tempo do mundo",
        "She's got a smile that it seems to me reminds me of childhood memories where everything was as fresh as the bright blue sky",
        "I've become so numb, I can't feel you there become so tired, so much more aware"
    };

    char mediumLyrics[10][100] = {
        "With a word she can get what she came for. Ooh, ooh, and she's buying a stairway to heaven."
        "Billie Jean is not my lover, She's just a girl who claims that I am the one",
        "Beat it, beat it, no one wants to be defeated",
        "Load up on guns, bring your friends it's fun to lose and to pretend, She's over-bored and self-assured Oh no, I know a dirty word",
        "All aboard, hahahahahahaha! Ai! Ai! Ai!",
        "Been spending most their lives, Living in a gangsta's paradise, Keep spending most our lives, Living in a gangsta's paradise",
        "When I'm away from you, I'm happier than ever, Wish I could explain it better, I wish it wasn't true",
        "Why'd you have to go and make things so complicated? I see the way you're, Actin' like you're somebody else, gets me frustrated",
        "If everything could ever feel this real forever, If anything could ever be this good again, The only thing I'll ever ask of you",
        "Don't waste your time on me, you're already, The voice inside my head, I miss you, miss you"
    };

    char hardLyrics[10][100] = {
        "I don't know what to do when she makes me sad, But I won't let this build up inside of me",
        "You told me think about it, well I did, Now I don't wanna feel a thing anymore, I'm tired of begging for the things that I want",
        "I know the truth now, I know who you are, And I don't love you anymore",
        "Sleep with one eye open, gripping your pillow tight",
        "Exit light, enter night, take my hand, we're off to never-never land"
    };

    char easyAnswers[10][50] = {
        "Queen",
        "Queen",
        "Michael Jackson",
        "Beatles",
        "Evanescence",
        "Tom Jobim",
        "Beatles",
        "Legiao Urbana",
        "Guns N Roses",
        "Linkin Park"
    };

    char mediumAnswers[10][50] = {
        "Led Zeppelin"
        "Michael Jackson",
        "Michael Jackson",
        "Nirvana",
        "Ozzy Osbourne",
        "Coolio",
        "Billie Eilish"
        "Avril Lavigne"
        "Foo Fighters"
        "Blink"
    };
    char hardAnswers[10][50] = {
        "Slipknot",
        "Pierce the Veil",
        "Evanescence",
        "Metallica",
        "Metallica"
    };

    printf("Bem-vindo ao jogo de adivinhação de música!\n");
    
    do {
        printf("\nEscolha o nível de dificuldade:\n");
        printf("1 - Fácil\n");
        printf("2 - Médio\n");
        printf("3 - Difícil\n");
        printf("Digite sua escolha: ");
        scanf("%d", &level);
        while (level < 1 || level > 3) {
            printf("Digite uma opção válida (1, 2 ou 3): ");
            scanf("%d", &level);
        }

        maxNumber = 9;

        if (level == 1) {
            printf("\nNível fácil selecionado! Adivinhe qual é a banda ou artista que canta a seguinte música:\n");
            randomNumber = rand() % (maxNumber + 1);
            printf("%s\n", easyLyrics[randomNumber]);
            strcpy(guess, easyAnswers[randomNumber]);
        } else if (level == 2) {
            printf("\nNível médio selecionado! Adivinhe qual é o artista que canta a seguinte música:\n");
            randomNumber = rand() % (maxNumber + 1);
            printf("%s\n", mediumLyrics[randomNumber]);
            strcpy(guess, mediumAnswers[randomNumber]);
        } else {
            printf("\nNível difícil selecionado! Adivinhe qual é a banda ou artista que canta a seguinte música:\n");
            randomNumber = rand() % (maxNumber + 1);
            printf("%s\n", hardLyrics[randomNumber]);
            strcpy(guess, hardAnswers[randomNumber]);
        }

        tries = 0;
        while (1) {
            printf("Qual é a sua resposta? ");
            scanf("%s", playAgain);
            getchar();

            tries++;

            if (strcmp(playAgain, guess) == 0) {
                printf("Parabéns! Você acertou em %d tentativas.\n", tries);
                break;
            } else {
                printf("Resposta incorreta. Tente novamente.\n");
            }
        }

        printf("Deseja jogar novamente? (S/N) ");
        scanf("%c", &playAgain);
        getchar(); 
    } while (playAgain == 'S' || playAgain == 's');

    printf("Obrigado por jogar pato!\n");

    return 0;
}
       