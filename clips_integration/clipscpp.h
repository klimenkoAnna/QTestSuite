#define CLIPS_COMPILED_AS_C_PLUS_PLUS 1

#include "setup.h"
#include "clips.h"

namespace Clips
{
    //#define CLIPS_COMPILED_AS_C_PLUS_PLUS 1

    class ClipsCPPRouter;

    class ClipsCPPEnv
    {
    private:
        void *theEnv;

    public:
        ClipsCPPEnv();
        ~ClipsCPPEnv();
        void Clear();
        int Load(char *);
        void Reset();
        long long Run(long long);
        int Watch(char *);
        int Unwatch(char *);
        int AddRouter(char *,int,ClipsCPPRouter *);
    };

    class ClipsCPPRouter
    {
    public:
        virtual int Query(ClipsCPPEnv *,char *);
        virtual int Print(ClipsCPPEnv *,char *,char *);
        virtual int Getc(ClipsCPPEnv *,char *);
        virtual int Ungetc(ClipsCPPEnv *,int,char *);
        virtual int Exit(ClipsCPPEnv *,int);
    };
}

//---------------------------------------------------------------------------------------

#include "qtestsuite_shareddefs.h"

class ClipsStdoutRouter : public Clips::ClipsCPPRouter
{
private:
    ostringstream buffer;

public:
    virtual int Print(Clips::ClipsCPPEnv *, char *logicalName, char *printString)
    {
        buffer << printString;
        return TRUE;
    }

    virtual int Query(Clips::ClipsCPPEnv *,char *)
    {
        return TRUE;
    }

    QString getBuffer()
    {
        return QString::fromUtf8( buffer.str().c_str() );
    }

    void emptyBuffer()
    {
        buffer.str("");
    }
};
