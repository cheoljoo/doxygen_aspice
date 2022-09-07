
def capitalize_first(str):
    """Capitalize the first character of string

    Args:
        str (str): string
        param2 (str): The second parameter.

    Returns:
        str: string that capitalized the first character

    """
    return str[:1].upper()+str[1:]

def get_return_type_from_api(d, main, sub, idx):
    """Get return type from api

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function

    Returns:
        str: return type of api

    """
    return d[main]['files'][sub]['functions']['members'][idx]['type']

def get_prototype_from_api(d, main, sub, idx):
    """Get prototype from api

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function

    Returns:
        str: prototype of api

    """
    return d[main]['files'][sub]['functions']['members'][idx]['name']

def build_handler_prototype(p):
    """Build new method name for module handler
    ex) 'dcmpf_audio_mute_cancel_audio_mute_on' => 'MuteCancelAudioMuteOn'

    Args:
        p (str): original prototype

    Returns:
        str: new method name for module handler

    """
    return p.split('_')[2] + "".join(map(capitalize_first, p.split('_')[3:]))

def get_parameter_type_from_api(d, main, sub, idx, param):
    """Get parameter type from api

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function
        param (str): index of parameter of function

    Returns:
        str: parameter type of api

    """
    return d[main]['files'][sub]['functions']['members'][idx]['parameters'][param]['type']

def is_parameter_type_pointer(d, main, sub, idx, param):
    """Get parameter type of pointer from api

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function
        param (str): index of parameter of function

    Returns:
        str: True if existed, otherwise False

    """
    return -1 != d[main]['files'][sub]['functions']['members'][idx]['parameters'][param]['type'].find('*')

def is_parameter_type_callback(d, main, sub, idx, param):
    """is parameter type callback from api

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function
        param (str): index of parameter of function

    Returns:
        str: True if existed, otherwise False

    """
    return d[main]['files'][sub]['functions']['members'][idx]['parameters'][param]['type'][-4:] == 'cb_t'


def get_parameter_name_from_api(d, main, sub, idx, param):
    """Get parameter type from api

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function
        param (str): index of parameter of function

    Returns:
        str: parameter name of api

    """
    return d[main]['files'][sub]['functions']['members'][idx]['parameters'][param]['declaration_name']

def get_comment_of_prototype_from_api(d, main, sub, idx):
    """Get comment of prototype from api

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function

    Returns:
        str: prototype of api

    """
    comment = 'TBD'
    if 'doc' in d[main]['files'][sub]['functions']['members'][idx]['brief']:
        comment = d[main]['files'][sub]['functions']['members'][idx]['brief']['doc']['2']['content']

    return comment

def recover_from_special_char(s):
    unusedCode = '''
    sub recover_special_code {
    my ($s) = @_;
    $s =~ s/#\+#\+#\+\+braceopen###/\{/g;
    $s =~ s/#\-#\-#\-\-braceclose###/\}/g;
    $s =~ s/#\=#\=#\=\=backslash###/\\/g;
    $s =~ s/#\%#\%#\%\%return###/\n/g;
    $s =~ s/#\&#\&#\&\&doublequotation###/\"/g;
    $s =~ s/#\&#\=#\&\&alpha###/\@/g;
    return $s;
}
'''
    s = s.replace('#+#+#++braceopen###','{')
    s = s.replace('#-#-#--braceclose###','}')
    s = s.replace('#=#=#==backslash###','\\')
    s = s.replace('#%#%#%%return###',' @n ')
    s = s.replace('#&#&#&&doublequotation###','"')
    s = s.replace('#&#=#&&alpha###','@')
    return s
    

def get_parameter_comment_from_api(d, main, sub, idx, param):
    """Get parameter's comment from api

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function
        param (str): index of parameter of function

    Returns:
        str: parameter name of api

    """
    comment = ''
    if 'doc' not in d[main]['files'][sub]['functions']['members'][idx]['detailed']:
        return 'TBD type-1'

    unusedCode = '''
D ['classes'] ['7'] ['public_methods'] ['members'] ['2']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['brief']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['brief'] ['doc']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['brief'] ['doc'] ['1']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['brief'] ['doc'] ['1'] ['type'] =  "parbreak"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['brief'] ['doc'] ['2']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['brief'] ['doc'] ['2'] ['content'] =  "onReceive(..) is the function to register receiver for the BpTidlSignalReceiver . "
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['brief'] ['doc'] ['2'] ['type'] =  "text"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['parameters']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['parameters'] ['1']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['parameters'] ['1'] ['declaration_name'] =  "receiver"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['parameters'] ['1'] ['type'] =  "const android::sp< ITidlSignalReceiver > &"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['parameters'] ['2']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['parameters'] ['2'] ['declaration_name'] =  "signalID"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['parameters'] ['2'] ['type'] =  "ETidlDid"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['1']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['1'] ['type'] =  "parbreak"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['2']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['2'] ['content'] =  "desc onReceive with did"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['2'] ['type'] =  "text"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['3']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['3'] ['type'] =  "parbreak"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['1']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['1'] ['doc']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['1'] ['doc'] ['1']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['1'] ['doc'] ['1'] ['content'] =  "android::sp< ITidlSignalReceiver > interface "
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['1'] ['doc'] ['1'] ['type'] =  "text"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['1'] ['parameters']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['1'] ['parameters'] ['1']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['1'] ['parameters'] ['1'] ['dir'] =  "in"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['1'] ['parameters'] ['1'] ['name'] =  "receiver"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['2']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['2'] ['doc']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['2'] ['doc'] ['1']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['2'] ['doc'] ['1'] ['type'] =  "parbreak"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['2'] ['doc'] ['2']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['2'] ['doc'] ['2'] ['content'] =  "ETidlDid"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['2'] ['doc'] ['2'] ['link'] =  "classETidlDid"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['2'] ['doc'] ['2'] ['type'] =  "url"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['2'] ['doc'] ['3']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['2'] ['doc'] ['3'] ['type'] =  "text"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['2'] ['doc'] ['3'] ['content'] =  " : enum with related class"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['2'] ['parameters']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['2'] ['parameters'] ['1']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['2'] ['parameters'] ['1'] ['dir'] =  "in"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc'] ['4'] ['params'] ['2'] ['parameters'] ['1'] ['name'] =  "signalID"
'''

    paramsIdx = ''
    for doci in d[main]['files'][sub]['functions']['members'][idx]['detailed']['doc']:
        if 'params' in d[main]['files'][sub]['functions']['members'][idx]['detailed']['doc'][doci]:
            paramsIdx = doci
            break

    if paramsIdx == '':
        return 'TBD type-2'
    #print("paramsIdx:",paramsIdx)
    # doc = d[main]['files'][sub]['functions']['members'][idx]['detailed']['doc']['2']['params'][param]['doc']
    doc = d[main]['files'][sub]['functions']['members'][idx]['detailed']['doc'][paramsIdx]['params'][param]['doc']
    for k in doc:
        cmnt_t = doc[k]['type']
        if (cmnt_t == 'text' or cmnt_t == 'url') and 'content' in doc[k]:
            comment += doc[k]['content']
        elif cmnt_t == 'linebreak':
            comment += ' @n '
            '''
        elif cmnt_t == 'ref':
            comment += '@ref ' + doc[k]['content']['1']['content']
            '''

    parameters = d[main]['files'][sub]['functions']['members'][idx]['parameters']
    dir  = ''
    params = d[main]['files'][sub]['functions']['members'][idx]['detailed']['doc'][paramsIdx]['params'][param]
    if 'parameters' in params  and 'dir' in params['parameters']['1']:
        dir = params['parameters']['1']['dir']
    unusedCode = '''
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['parameters'] ['1']={}
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['parameters'] ['1'] ['declaration_name'] =  "receiver"
D ['classes'] ['7'] ['public_methods'] ['members'] ['2'] ['parameters'] ['1'] ['type'] =  "const android::sp< ITidlSignalReceiver > &"
'''
    #comment = parameters[param]['type'] + " " + parameters[param]['declaration_name'] + " [{}] ".format(dir) + comment
    comment += " [{}]".format(dir)
    return recover_from_special_char(comment)

def is_function_existed(d, main, sub):
    """Check if function is existed in this module or not

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name

    Returns:
        str: True if existed, otherwise False

    """
    return 'functions' in d[main]['files'][sub]

def get_all_sub_modules(d, main):
    """Get all sub modules

    Args:
        d (dict): data source to query
        main (str): main module name

    Returns:
        str: all sub modules

    """
    return d[main]['files']

def get_all_functions(d, main, sub):
    """Get all functions

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name

    Returns:
        str: all funtions of sub module

    """
    return d[main]['files'][sub]['functions']['members']

def get_all_parameters(d, main, sub, idx):
    """Get all parameters

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function

    Returns:
        str: all parameter of function

    """
    return d[main]['files'][sub]['functions']['members'][idx]['parameters']

def is_sync_function(d, main, sub, idx):
    """Check if this function is synchronous or not

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function

    Returns:
        bool: Ture for synchronous, otherwise False

    """

    for k in get_all_parameters(d, main, sub, idx):
        if get_parameter_type_from_api(d, main, sub, idx, k)[-4:] == 'cb_t' :
            return False

    return True

def is_with_handle_function(d, main, sub, idx):
    """Check if this function with handle or not

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function

    Returns:
        bool: Ture for with handle, otherwise False

    """
    for k in get_all_parameters(d, main, sub, idx):
        if get_parameter_name_from_api(d, main, sub, idx, k) == 'handle':
            return True

    return False

def skip_sub_module(d, main, sub, config):
    """Check if sub module should be skipped or not

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        config (dict): config data

    Returns:
        str: True if this should be skipped, otherwise False

    """
    file = d[main]['files'][sub]['name'] # sub module name
    return True if 'skipsFiles' in config and file in config['skipsFiles'] else False

def skip_function(d, main, sub, idx, config):
    """Check if current function should be skipped or not

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function
        config (dict): config data

    Returns:
        str: True if this should be skipped, otherwise False

    """
    fn = d[main]['files'][sub]['functions']['members'][idx]['name'] # function name
    # skips common functions
    if fn[-14:] == 'context_create' or fn[-15:] == 'context_release':
        return True
    return True if 'skipsFunctions' in config and fn in config['skipsFunctions'] else False

def get_config_by_key(k):
    """Get config data by key(module name)

    Args:
        k (str): key, module name

    Returns:
        dict: config data

    """

    if k == "":
        return {}

    import json

    try:
        with open(f'../template/config/{k}.json', "r") as f:
            return json.loads(ignore_comments(f))
    except FileNotFoundError as e:
        print(f'confing not found for {k}, {e}')
        return {}

def get_submodules(k):
    """Get submodules by key(module name)

    Args:
        k (str): key, module name

    Returns:
        dict: sub modules

    """
    import json

    try:
        with open(f'../template/config/{k}.json', "r") as f:
            return json.loads(ignore_comments(f))['includes']
    except FileNotFoundError as e:
        print(f'confing not found for {k}, {e}')
        return {}

def ignore_comments(f):
    """Ignore comments line for variant in config json file
       Ignorance comment is starting "//" in line
       ex) // @CGA_VARIANT_START{"device.json:VARIANT_AREA}"}

    Args:
        f (file): file object maps to json file

    Returns:
        str: buffered json text string

    """
    buffer = ""
    for line in f.readlines():
        buffer = buffer + line if line.find('//') != 0 else buffer
    return buffer

def is_typedefs_existed(d, main, sub):
    """Check if typedefs is existed in this module or not

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name

    Returns:
        str: True if existed, otherwise False

    """
    return 'typedefs' in d[main]['files'][sub]

def get_all_callback_function(d, main, sub):
    """Get all callback functions

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name

    Returns:
        str: all funtions of callback

    """
    return d[main]['files'][sub]['typedefs']['members']

def get_callback_function_type(d, main, sub, idx):
    """ Get callback_function type from api

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function

    Returns:
        str: callback function type

    """
    return d[main]['files'][sub]['typedefs']['members'][idx]['type']

def is_arguments_existed(d, main, sub, idx):
    """Check if arguments is existed in this module or not

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function

    Returns:
        str: True if existed, otherwise False

    """
    return 'arguments' in d[main]['files'][sub]['typedefs']['members'][idx]

def get_callback_function_arguments(d, main, sub, idx):
    """ Get callback_function arguments from api

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function

    Returns:
        str: callback function arguments ex) "(dcmpf_handle_t handle)"

    """
    #buf = d[main]['files'][sub]['typedefs']['members'][idx]['arguments']
    #return buf[2:-1].split(', ')
    buf = d[main]['files'][sub]['typedefs']['members'][idx]['arguments']
    return buf[1:]

def is_callback_function_name(d, main, sub, idx):
    """ Get callback_function arguments from api

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function

    Returns:
        True : callback function other False

    """
    buff = d[main]['files'][sub]['typedefs']['members'][idx]['name']
    if buff[-4:] == 'cb_t' :
        return True

    return False 

def get_callback_function_name(d, main, sub, idx):
    """ Get callback_function name from api

    Args:
        d (dict): data source to query
        main (str): main module name
        sub (str): sub module name
        idx (str): index of function

    Returns:
        str : callback function name

    """
    return d[main]['files'][sub]['typedefs']['members'][idx]['name']

def get_doc(indent,prefix,doc,debug="debug"):
    """ get doc of brief or detailed

    Args:
        indent (int): indent size (tabsize = 4)
        prefix (str): '- ' in case of markdown
        doc (variable:dictionary): 'doc' variable ex) D ['classes'] ['10'] ['detailed'] ['doc']
        debug (str): optional for debugging

    Returns:
        str : document

    """
    firstLine = "{} ".format(prefix)
    ans = ""
    start = '    '*indent + "{} ".format(prefix)
    startFlag = 0
    subAns = ""
    for k in doc:
        if 'type' not in doc[k]:
            continue
        cmnt_t = doc[k]['type']
        if (cmnt_t == 'text' or cmnt_t == 'url') and 'content' in doc[k]:
            subAns += doc[k]['content']
        elif cmnt_t == 'parbreak':
            pass
        elif cmnt_t == 'plantuml':
            subAns += '\n```puml\n'
            subAns += doc[k]['content'] + '\n'
            subAns += '```\n'
            ans += subAns
            subAns = ""
            startFlag = 1
        elif cmnt_t == 'linebreak':
            # print("L{}[{}]".format(debug,subAns))
            if subAns.strip() != "":
                if startFlag == 1 :
                    ans += start + subAns + '\n'
                else :
                    ans += firstLine + subAns + '\n'
            subAns = ""
            startFlag = 1
        else :
            ans += '\n==another type:{}\n'.format(doc[k]['type'])
        # print("ans:",ans)
        # print("E{}[{}]".format(debug,subAns))
    if subAns.strip() != "":
        if startFlag == 1 :
            ans += start + subAns
        else :
            ans += firstLine + subAns
    # print("final-ans:",ans)
    return recover_from_special_char(ans)
def ref_doc_params(doc,debug="debug"):
    """ get dictionary of 'doc'

    Args:
        doc (variable:dictionary): 'doc' variable ex) D ['classes'] ['10'] ['detailed'] ['doc']
        debug (str): optional for debugging

    Returns:
        dictionary of 'params'
    """
    if doc == None:
        return None
    for k in doc:
        if 'params' in doc[k]:
            return doc[k]['params']
    return None
