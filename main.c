#define PTSNAME_SIZE 1024

struct pt_info {
    int master_fd;
    char slave_name[PTSNAME_SIZE];
};

void create_pt(struct pt_info *p){
    p -> master_fd = posix_openpt(O_RDWR);
    grantpt( p -> master_fd );
    unlockpt( p -> master_fd );
    ptsname_r( p -> master_fd, p -> slave_name, PTSNAME_SIZE );
}