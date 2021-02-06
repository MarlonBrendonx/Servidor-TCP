## Execução :computer:
**Conceda permissão de execução e compile com gcc **
```bash
chmod +x main.c
gcc -o server-tcp main.c
./server-tcp
```
## Teste
Execute o comando telnet na porta 8000 para testar a conexão do servidor
```bash
telnet 127.0.0.1 8000
```
## Resultado Esperado

```bash
Socket:: Success
Bind: : Success
Listen:: Success
Accept:: Success

Accept:: Success
Recebendo conexao de: 127.0.0.1
```
