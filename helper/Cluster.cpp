#include <iostream>
#include <queue>
#include <thread>
#include <assert.h>

#include "cpp-hiredis-cluster/include/hirediscommand.h"

using namespace RedisCluster;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

void createDatabaseColumns(string ipAddress, int port, string database, string table, string msgPackString)
{
    Cluster<redisContext>::ptr_t cluster_p;
    redisReply * reply;
    // cluster_p = HiredisCommand<>::createCluster( "0.0.0.0", 7000 );
    cluster_p = HiredisCommand<>::createCluster( ipAddress, port );
    reply = static_cast<redisReply*>( HiredisCommand<>::Command( cluster_p, "database-description", "HSET %s %s-%s %s", "database-description", database, table, msgPackString));
    
    if( reply->type == REDIS_REPLY_STATUS  || reply->type == REDIS_REPLY_ERROR )
    {
        cout << " Reply to HSET database-description BAR " << endl;
        cout << reply->str << endl;
    }
    
    freeReplyObject( reply );
    delete cluster_p;
}

// ZCOUNT myzset -inf +inf

void insertDatabaseTable(string ipAddress, int port, string database, string table){
    Cluster<redisContext>::ptr_t cluster_p;
    redisReply * reply;
    redisReply * reply2;
    int count = 0;
    // cluster_p = HiredisCommand<>::createCluster( "0.0.0.0", 7000 );
    cluster_p = HiredisCommand<>::createCluster( ipAddress, port );
    reply = static_cast<redisReply*>( HiredisCommand<>::Command( cluster_p, "list-database", "ZCOUNT list-database -inf +inf")); //Add here reply no.
    
    if( reply->type == REDIS_REPLY_STATUS  || reply->type == REDIS_REPLY_ERROR )
    {
        cout << " Reply to SET FOO BAR " << endl;
        cout << reply->str << endl;
    }
    count = reply->stt + 1;
    reply2 = static_cast<redisReply*>( HiredisCommand<>::Command( cluster_p, "list-database", "ZADD list-database %i %s-%s", count, database, table)); //Add here reply no.
    if( reply2->type == REDIS_REPLY_STATUS  || reply2->type == REDIS_REPLY_ERROR )
    {
        cout << " Reply to SET FOO BAR " << endl;
        cout << reply2->str << endl;
    }
    freeReplyObject( reply );
    freeReplyObject( reply2 );
    delete cluster_p;
}

void insertHashValueMaps(int count, string value, string database, string table){
    Cluster<redisContext>::ptr_t cluster_p;
    redisReply * reply;
    // cluster_p = HiredisCommand<>::createCluster( "0.0.0.0", 7000 );
    cluster_p = HiredisCommand<>::createCluster( ipAddress, port );
    reply = static_cast<redisReply*>( HiredisCommand<>::Command( cluster_p, "%s-%s", "HSET %s-%s %s-%s %s", database, table, database, table, count, value, getStringRelation(count, value)));

    if( reply->type == REDIS_REPLY_STATUS  || reply->type == REDIS_REPLY_ERROR )
    {
        cout << " Reply to HSET database-description BAR " << endl;
        cout << reply->str << endl;
    }
    
    freeReplyObject( reply );
    delete cluster_p;
}



// int main(int argc, const char * argv[])
// { u
//     try
//     {
//         processClusterCommand();
//     } catch ( const RedisCluster::ClusterException &e )
//     {
//         cout << "Cluster exception: " << e.what() << endl;
//     }
//     return 0;
// }