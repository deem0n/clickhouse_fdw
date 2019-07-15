#ifndef CLICKHOUSE_BINARY_H
#define CLICKHOUSE_BINARY_H

typedef struct ch_binary_connection_t ch_binary_connection_t;
typedef struct ch_binary_response_t
{
	const void		   *block;
	char				query_id[30];
} ch_binary_response_t;

extern "C" {

ch_binary_connection_t *ch_binary_connect(char *host, int port,
		char *database, char *user, char *password);
void ch_binary_close(ch_binary_connection_t *conn);
ch_binary_response_t *ch_binary_simple_query(ch_binary_connection_t *conn,
		const char *query, uint32_t query_id);

}

#endif