int compare(const void *a,const void *b)
{
    int *p1=(int*)a;
    int *p2=(int*)b;
    
    return (*p1-*p2);
}

int bagOfTokensScore(int* tokens, int tokensSize, int P)
{
    int i = 0, j = tokensSize - 1;
    int score = 0;
    
    if(tokensSize > 1)
    {
        qsort(tokens, tokensSize, sizeof(int), compare);
    }
    
    while(i <= j)
    {
        if(tokens[i] <= P)
        {
            P -= tokens[i];
            score++;
            i++;
        }
        else if(score >= 1)
        {
            if(i == j)
            {
                break;
            }
            
            P += tokens[j];
            score--;
            j--;
        }
        else
        {
            break;
        }
    }
    
    return score;
}