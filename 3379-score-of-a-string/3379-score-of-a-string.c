int scoreOfString(char* string) {
    int pontuacao = 0;
    for (int i = 0; string[i+1] != '\0'; i++){
        pontuacao = pontuacao + abs(string[i] - string[i+1]);
    }
    return pontuacao;
}