/*
 * SPOJ PT07Z
 * 09/16/16
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t path[10001][10001];
int     n;

void dfs( int start_node, int depth, int* final_node, int* max_depth ) {
    int i;
    if ( *max_depth < depth ) {
        *max_depth  = depth;
        if(final_node)*final_node = start_node;
    }
    for ( i = 0; i < n+1; i++ ) {
        if ( path[start_node][i] ) {
            //printf("now %d trying to %d\n", start_node, i);
            path[start_node][i] = 0;
            path[i][start_node] = 0;
            dfs( i, depth + 1, final_node, max_depth );
            path[start_node][i] = 1;
            path[i][start_node] = 1;
        }
    }
};

int main() {
    uint16_t i;
    for ( i = 0; i < 10001; i++ ) {
        memset( path[i], 0, 10001 * sizeof( uint8_t) );
    }

    int start_node;
    scanf( "%d", &n );
    for ( i = 0; i < n-1; i++ ) {
        int node_a, node_b;
        scanf( "%d%d", &node_a, &node_b );
        path[node_a][node_b] = 1;
        path[node_b][node_a] = 1;
        start_node           = node_a;
    }

    int final_node = start_node, depth = 0;

    dfs( start_node, 0, &final_node, &depth );
    dfs( final_node, 0, NULL, &depth );

    printf( "%d\n", depth );

    return 0;
}
