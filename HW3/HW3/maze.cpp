bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
    maze[sr][sc] = '*';
    bool result = false;
    if (sr == er && sc == ec)
        return true;
    //north
    if (maze[sr-1][sc] == '.')
        result = pathExists(maze, nRows, nCols, sr-1, sc, er, ec);
    if (result)
        return true;

    //south
    if (maze[sr+1][sc] == '.')
        result = pathExists(maze, nRows, nCols, sr+1, sc, er, ec);
    if (result)
        return true;

    //east
    if (maze[sr][sc+1] == '.')
        result = pathExists(maze, nRows, nCols, sr, sc+1, er, ec);
    if (result)
        return true;

    //west
    if (maze[sr][sc-1] == '.')
        result = pathExists(maze, nRows, nCols, sr, sc-1, er, ec);
    if (result)
        return true;

    return false;
}
