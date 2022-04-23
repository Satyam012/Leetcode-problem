class Solution {
private:
    unordered_map<string,string> db;
    string base64Strs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string base62Encoding(int unix){
        string tinyURL;
        while(unix > 0){
            tinyURL += base64Strs[unix % 62];
            unix /= 62;
        }
        return tinyURL;
    }
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        time_t id = time(NULL);
        //http://tinyurl.com/4e9iAk
        string shortenURL = base62Encoding(id);
        string tinyURL = "http://tinyurl.com/"+ shortenURL;
        db[shortenURL] = longUrl;
        return tinyURL;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        //"https://leetcode.com/problems/design-tinyurl"
        //http://tinyurl.com/bNiRXb

        string code;
        for(int i = 19;i<shortUrl.size();i++) code += shortUrl[i];
        return db[code];
    }
};